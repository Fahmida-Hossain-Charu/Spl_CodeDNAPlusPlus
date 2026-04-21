#include "file_reader.h"
#include "tokenizer.h"
#include "feature_vector.h"

#include "similarity/cosine.h"
#include "similarity/euclidean.h"
#include "similarity/jaccard.h"
#include "similarity/edit_distance.h"
#include "similarity/hybrid.h"

#include "ascii_output.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define MAX_FILES 10

int is_c_file(const char* name)
{
    int len = strlen(name);
    return (len > 2 && name[len-2] == '.' && name[len-1] == 'c');
}

void process_pair(const char* f1, const char* f2)
{
    FileContent a,b;
    TokenList t1,t2;
    FeatureVector v1,v2;

    init_filecontent(&a);
    init_filecontent(&b);
    init_tokenlist(&t1);
    init_tokenlist(&t2);

    if (read_file(f1,&a)!=0 || read_file(f2,&b)!=0)
    {
        printf("Error reading files\n");
        return;
    }

    tokenize_file(&a,&t1);
    tokenize_file(&b,&t2);

    build_feature_vector(&a,&t1,&v1);
    build_feature_vector(&b,&t2,&v2);

    normalize_feature_vector(&v1);
    normalize_feature_vector(&v2);
  

    double cos = cosine_similarity(&v1,&v2);
    double eu  = euclidean_similarity(&v1,&v2);
    double jac = jaccard_similarity(&v1,&v2);
    double edit= normalized_edit_similarity(&v1,&v2);

    double hybrid = (cos + eu + jac + edit) / 4.0;

    print_similarity(f1,f2,cos,eu,jac,edit,hybrid);

    free_filecontent(&a);
    free_filecontent(&b);
}

void process_multi()
{
    int n;
    char files[MAX_FILES][256];

    printf("How many files (2-10): ");
    scanf("%d",&n);
    getchar();

    if (n < 2 || n > 10)
    {
        printf("Invalid range\n");
        return;
    }

    FileContent fc[MAX_FILES];
    TokenList tk[MAX_FILES];
    FeatureVector fv[MAX_FILES];

    for (int i = 0; i < n; i++)
    {
        printf("File %d: ", i+1);
        fgets(files[i],256,stdin);
        files[i][strcspn(files[i],"\n")] = 0;

        init_filecontent(&fc[i]);
        init_tokenlist(&tk[i]);

        if (read_file(files[i],&fc[i]) != 0)
        {
            printf("Cannot read %s\n", files[i]);
            return;
        }

        tokenize_file(&fc[i],&tk[i]);
        build_feature_vector(&fc[i],&tk[i],&fv[i]);

        normalize_feature_vector(&fv[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            double cos = cosine_similarity(&fv[i],&fv[j]);
            double eu  = euclidean_similarity(&fv[i],&fv[j]);
            double jac = jaccard_similarity(&fv[i],&fv[j]);
            double edit= normalized_edit_similarity(&fv[i],&fv[j]);

            double hybrid = (cos + eu + jac + edit) / 4.0;

            print_similarity(files[i],files[j],cos,eu,jac,edit,hybrid);
        }
    }
}

void process_folder()
{
    char path[256];
    char files[MAX_FILES][256];
    int count = 0;

    printf("Folder path: ");
    fgets(path,256,stdin);
    path[strcspn(path,"\n")] = 0;

    DIR* d = opendir(path);
    if (!d)
    {
        printf("Cannot open folder\n");
        return;
    }

    struct dirent* e;

    while ((e = readdir(d)) != NULL && count < MAX_FILES)
    {
        if (!strcmp(e->d_name,".") || !strcmp(e->d_name,".."))
            continue;

        if (!is_c_file(e->d_name))
            continue;

        snprintf(files[count],256,"%s/%s",path,e->d_name);
        count++;
    }

    closedir(d);

    if (count < 2)
    {
        printf("Not enough .c files\n");
        return;
    }

    FileContent fc[MAX_FILES];
    TokenList tk[MAX_FILES];
    FeatureVector fv[MAX_FILES];

    for (int i = 0; i < count; i++)
    {
        init_filecontent(&fc[i]);
        init_tokenlist(&tk[i]);

        if (read_file(files[i],&fc[i]) != 0)
        {
            printf("Cannot read %s\n", files[i]);
            return;
        }

        tokenize_file(&fc[i],&tk[i]);
        build_feature_vector(&fc[i],&tk[i],&fv[i]);
        normalize_feature_vector(&fv[i]);
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            double cos = cosine_similarity(&fv[i],&fv[j]);
            double eu  = euclidean_similarity(&fv[i],&fv[j]);
            double jac = jaccard_similarity(&fv[i],&fv[j]);
            double edit= normalized_edit_similarity(&fv[i],&fv[j]);

            double hybrid = (cos + eu + jac + edit) / 4.0;

            print_similarity(files[i],files[j],cos,eu,jac,edit,hybrid);
        }
    }
}

int main()
{
    int choice;

    printf("CodeDNA++ Running...\n");

    while (1)
    {
        printf("\n========== CodeDNA++ ==========\n");
        printf("1. Compare two files\n");
        printf("2. Compare multiple files (2-10)\n");
        printf("3. Compare folder (.c files)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d",&choice) != 1)
        {
            printf("Invalid input\n");
            while(getchar()!='\n');
            continue;
        }

        getchar(); 

        if (choice == 4) break;

        if (choice == 1)
        {
            char a[256], b[256];

            printf("File 1: ");
            fgets(a,256,stdin);
            a[strcspn(a,"\n")] = 0;

            printf("File 2: ");
            fgets(b,256,stdin);
            b[strcspn(b,"\n")] = 0;

            process_pair(a,b);
        }
        else if (choice == 2)
        {
            process_multi();
        }
        else if (choice == 3)
        {
            process_folder();
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}