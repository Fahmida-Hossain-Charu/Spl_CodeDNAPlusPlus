#include "operator.h"
#include <string.h>

static const char* c_operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">="
};

double compute_operator_density(const TokenList* token_list) {
    int operator_count = 0;
    for (int i = 0; i < token_list->count; i++) {
        for (int j = 0; j < sizeof(c_operators)/sizeof(c_operators[0]); j++) {
            if (strcmp(token_list->tokens[i], c_operators[j]) == 0) {
                operator_count++;
                break;
            }
        }
    }
    return (double)operator_count / token_list->count;
}
