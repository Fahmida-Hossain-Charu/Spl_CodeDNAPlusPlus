#include "comment.h"
#include <string.h>
#include <stdio.h>

double compute_comment_ratio(const char* content) {
    int lines = 0, comment_lines = 0;
    char buffer[1024];
    FILE* f = tmpfile();
    fputs(content, f);
    rewind(f);

    while (fgets(buffer, sizeof(buffer), f)) {
        lines++;
        if (strstr(buffer, "//") || strstr(buffer, "/*")) {
            comment_lines++;
        }
    }
    fclose(f);
    return lines > 0 ? (double)comment_lines / lines : 0.0;
}
