#include "file_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* safe_strdup(const char* s)
{
    size_t len = strlen(s) + 1;
    char* p = (char*)malloc(len);
    if (!p) return NULL;
    memcpy(p, s, len);
    return p;
}

void init_filecontent(FileContent* fc)
{
    fc->lines = NULL;
    fc->line_count = 0;
}

void free_filecontent(FileContent* fc)
{
    if (!fc || !fc->lines) return;

    for (int i = 0; i < fc->line_count; i++)
        free(fc->lines[i]);

    free(fc->lines);
    fc->lines = NULL;
    fc->line_count = 0;
}

int read_file(const char* path, FileContent* fc)
{
    FILE* fp = fopen(path, "r");
    if (!fp) return -1;

    init_filecontent(fc);

    char buffer[1024];
    int cap = 64;

    fc->lines = (char**)malloc(sizeof(char*) * cap);
    if (!fc->lines)
    {
        fclose(fp);
        return -1;
    }

    fc->line_count = 0;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        if (fc->line_count >= cap)
        {
            cap *= 2;
            char** tmp = realloc(fc->lines, sizeof(char*) * cap);
            if (!tmp)
            {
                fclose(fp);
                return -1;
            }
            fc->lines = tmp;
        }

        fc->lines[fc->line_count] = safe_strdup(buffer);

        if (!fc->lines[fc->line_count])
        {
            fclose(fp);
            return -1;
        }

        fc->line_count++;
    }

    fclose(fp);
    return 0;
}