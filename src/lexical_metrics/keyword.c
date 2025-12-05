#include "keyword.h"
#include <string.h>

static const char* c_keywords[] = {
    "int", "float", "double", "char", "return", "if", "else", "for", "while", "switch", "case"
};

double compute_keyword_density(const TokenList* token_list) {
    int keyword_count = 0;
    for (int i = 0; i < token_list->count; i++) {
        for (int j = 0; j < sizeof(c_keywords)/sizeof(c_keywords[0]); j++) {
            if (strcmp(token_list->tokens[i], c_keywords[j]) == 0) {
                keyword_count++;
                break;
            }
        }
    }
    return (double)keyword_count / token_list->count;
}
