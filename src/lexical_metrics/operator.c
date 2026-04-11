#include "lexical_metrics/operator.h"
#include "utils.h"
#include <string.h>

static int is_operator_token(const char* token) {
    if (!token || strlen(token) == 0) return 0;
    size_t len = strlen(token);
    for (size_t i = 0; i < len; i++) {
        if (!is_operator_char(token[i])) return 0;
    }
    return 1;
}

void analyze_operators(const TokenList* tokens, OperatorMetrics* metrics) {
    metrics->total = 0;
    for (int i = 0; i < tokens->count; i++) {
        if (is_operator_token(tokens->tokens[i])) {
            metrics->total++;
        }
    }
}