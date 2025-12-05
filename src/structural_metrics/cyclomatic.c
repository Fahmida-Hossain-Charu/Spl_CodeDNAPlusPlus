#include "cyclomatic.h"
#include <string.h>

int compute_cyclomatic(const char* content) {
    int complexity = 1; // default
    const char* keywords[] = { "if", "for", "while", "case", "&&", "||" };
    for (int i = 0; content[i]; i++) {
        for (int k = 0; k < sizeof(keywords)/sizeof(keywords[0]); k++) {
            if (strncmp(&content[i], keywords[k], strlen(keywords[k])) == 0) {
                complexity++;
            }
        }
    }
    return complexity;
}
