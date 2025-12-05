#include "loc.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int count_loc(const char* content) {
    int loc = 0;
    int in_comment = 0;
    char line[1024];
    FILE* f = tmpfile();
    fputs(content, f);
    rewind(f);

    while (fgets(line, sizeof(line), f)) {
        char* ptr = line;
        while (*ptr && isspace(*ptr)) ptr++;
        if (*ptr == '\0') continue; // skip empty
        if (strncmp(ptr, "/*", 2) == 0) in_comment = 1;
        if (in_comment) {
            if (strstr(ptr, "*/")) in_comment = 0;
            continue;
        }
        if (strncmp(ptr, "//", 2) == 0) continue; // single line comment
        loc++;
    }
    fclose(f);
    return loc;
}
