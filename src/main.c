#include "file_reader.h"
#include "tokenizer.h"
#include "feature_vector.h"

#include "lexical_metrics/keyword.h"
#include "lexical_metrics/operator.h"
#include "lexical_metrics/identifier.h"
#include "lexical_metrics/comment.h"

#include "structural_metrics/loc.h"
#include "structural_metrics/function.h"
#include "structural_metrics/cyclomatic.h"
#include "structural_metrics/nesting_depth.h"
#include "structural_metrics/statement.h"

#include "similarity/cosine.h"
#include "similarity/euclidean.h"
#include "similarity/jaccard.h"
#include "similarity/edit_distance.h"
#include "similarity/hybrid.h"

#include "ascii_output.h"
#include "config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void analyze_file(const char* filename) {
    FileContent file;
    TokenList tokens;
    
    printf("\nAnalyzing: %s\n", filename);
    printf("====================\n");
    
    if (read_file(filename, &file) != 0) {
        printf("Error: Cannot read file %s\n", filename);
        return;
    }
    
    if (tokenize_file(&file, &tokens) != 0) {
        printf("Error: Cannot tokenize file %s\n", filename);
        return;
    }
    
    KeywordMetrics kw;
    OperatorMetrics op;
    IdentifierMetrics id;
    CommentMetrics cm;
    
    LOCMetrics loc;
    FunctionMetrics func;
    CyclomaticMetrics cyclo;
    NestingMetrics nest;
    StatementMetrics stmt;
    
    analyze_keywords(&tokens, &kw);
    analyze_operators(&tokens, &op);
    analyze_identifiers(&tokens, &id);
    analyze_comments(&file, &cm);
    
    analyze_loc(&file, &loc);
    analyze_functions(&file, &func);
    analyze_cyclomatic(&file, &cyclo);
    analyze_nesting_depth(&file, &nest);
    analyze_statements(&file, &stmt);
    
    print_lexical_metrics(filename, &kw, &op, &id, &cm);
    print_structural_metrics(filename, &loc, &func, &cyclo, &nest, &stmt);
}

void compare_files(const char* file1, const char* file2) {
    FileContent f1, f2;
    TokenList t1, t2;
    
    printf("\nComparing: %s vs %s\n", file1, file2);
    printf("====================\n");
    
    if (read_file(file1, &f1) != 0 || read_file(file2, &f2) != 0) {
        printf("Error: Cannot read files\n");
        return;
    }
    
    if (tokenize_file(&f1, &t1) != 0 || tokenize_file(&f2, &t2) != 0) {
        printf("Error: Cannot tokenize files\n");
        return;
    }
    
    double cosine = cosine_similarity(&t1, &t2);
    double euclid = euclidean_distance(&t1, &t2);
    double jaccard = jaccard_similarity(&t1, &t2);
    double edit = normalized_edit_similarity(&t1, &t2);
    double hybrid = hybrid_similarity(&t1, &t2);
    
    print_similarity(file1, file2, cosine, euclid, jaccard, edit, hybrid);
}

int is_c_file(const char* filename) {
    int len = strlen(filename);
    if (len < 3) return 0;
    return (filename[len-2] == '.' && filename[len-1] == 'c');
}

void process_folder(const char* folder_path) {
    DIR *d;
    struct dirent *dir;
    char* files[100];
    int file_count = 0;
    
    d = opendir(folder_path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (is_c_file(dir->d_name)) {
                char full_path[512];
                snprintf(full_path, sizeof(full_path), "%s/%s", folder_path, dir->d_name);
                files[file_count] = malloc(strlen(full_path) + 1);
                strcpy(files[file_count], full_path);
                file_count++;
            }
        }
        closedir(d);
    } else {
        printf("Error: Cannot open folder %s\n", folder_path);
        return;
    }
    
    if (file_count == 0) {
        printf("No .c files found in folder\n");
        return;
    }
    
    printf("\nFound %d .c files in folder\n", file_count);
    
    for (int i = 0; i < file_count; i++) {
        analyze_file(files[i]);
    }
    
    printf("\nPAIRWISE COMPARISONS FOR ALL FILES IN FOLDER\n");
    printf("============================================\n");
    for (int i = 0; i < file_count; i++) {
        for (int j = i + 1; j < file_count; j++) {
            compare_files(files[i], files[j]);
        }
    }
    
    for (int i = 0; i < file_count; i++) {
        free(files[i]);
    }
}

int main() {
    int choice;
    char input[512];
    
    while (1) {
        printf("\nCodeDNA++ - Code Similarity Analyzer\n");
        printf("====================================\n");
        printf("1. Compare specific files\n");
        printf("2. Compare all .c files in a folder\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1: {
                char files[10][256];
                int file_count = 0;
                
                printf("Enter .c file names (enter 'done' when finished):\n");
                while (file_count < 10) {
                    printf("File %d: ", file_count + 1);
                    fgets(files[file_count], 256, stdin);
                    files[file_count][strcspn(files[file_count], "\n")] = 0;
                    
                    if (strcmp(files[file_count], "done") == 0) {
                        break;
                    }
                    
                    if (!is_c_file(files[file_count])) {
                        printf("Not a .c file. Please enter a .c file\n");
                        continue;
                    }
                    
                    file_count++;
                }
                
                if (file_count < 2) {
                    printf("Need at least 2 files to compare\n");
                    break;
                }
                
                for (int i = 0; i < file_count; i++) {
                    analyze_file(files[i]);
                }
                
                printf("\nPAIRWISE COMPARISONS\n");
                printf("====================\n");
                for (int i = 0; i < file_count; i++) {
                    for (int j = i + 1; j < file_count; j++) {
                        compare_files(files[i], files[j]);
                    }
                }
                break;
            }
            
            case 2: {
                char folder_path[256];
                printf("Enter folder path: ");
                fgets(folder_path, 256, stdin);
                folder_path[strcspn(folder_path, "\n")] = 0;
                process_folder(folder_path);
                break;
            }
            
            case 3:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}