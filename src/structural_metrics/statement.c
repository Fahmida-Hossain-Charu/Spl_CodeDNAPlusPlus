#include "statement.h"
#include <string.h>
#include <stdio.h>

double average_statement_length(const char* content) {
    int stmt_count = 0, line_count = 0;
    char buffer[1024];
    FILE* f = tmpfile();
    fputs(content, f);
    rewind(f);

    while (fgets(buffer, sizeof(buffer), f)) {
        line_count++;
        if (strchr(buffer, ';')) stmt_count++;
    }
    fclose(f);
    return stmt_count ? (double)line_count / stmt_count : 0.0;
}
