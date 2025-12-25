#include "lexical_metrics/operator.h"
#include "utils.h"
#include <string.h>

static int is_operator_token(const char* token) {
    if (!token || strlen(token)==0) return 0;
    int len = strlen(token);
    for (int i=0;i<len;i++) {
        if (!is_operator_char(token[i])) return 0;
    }
    return 1;
}

void analyze_operators(const TokenList* tokens, OperatorMetrics* metrics) {
    metrics->total = 0;
    memset(metrics->counts,0,sizeof(metrics->counts));

    for (int i=0;i<tokens->count;i++) {
        if (is_operator_token(tokens->tokens[i])) {
            int idx = tokens->tokens[i][0]%128;
            metrics->counts[idx]++;
            metrics->total++;
        }
    }
}

int get_total_operators(const OperatorMetrics* metrics) {
    return metrics->total;
}
