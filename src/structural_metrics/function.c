#include "function.h"
#include <string.h>
#include <stdio.h>

int count_functions(const char* content) {
    int count = 0;
    const char* ptr = content;
    while (*ptr) {
        if (strstr(ptr, "void ") || strstr(ptr, "int ") || strstr(ptr, "char ") ||
            strstr(ptr, "float ") || strstr(ptr, "double ")) {
            const char* paren = strchr(ptr, '(');
            const char* brace = strchr(ptr, '{');
            if (paren && brace && paren < brace) count++;
        }
        ptr++;
    }
    return count;
}
