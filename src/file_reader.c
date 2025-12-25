#include "file_reader.h"
#include <string.h>

int read_file(const char* path, FileContent* fileData) {
    FILE* f = fopen(path, "r");
    if (!f) return -1;

    fileData->line_count = 0;

    while (fgets(fileData->lines[fileData->line_count], 512, f)) {
        int len = strlen(fileData->lines[fileData->line_count]);
        if (len > 0 && fileData->lines[fileData->line_count][len - 1] == '\n')
            fileData->lines[fileData->line_count][len - 1] = '\0';

        fileData->line_count++;

        if (fileData->line_count >= 5000)
            break;
    }

    fclose(f);
    return 0;
}
