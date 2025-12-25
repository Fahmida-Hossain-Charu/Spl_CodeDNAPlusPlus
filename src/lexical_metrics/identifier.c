#include "lexical_metrics/identifier.h"
#include "utils.h"
#include <string.h>

void analyze_identifiers(const TokenList* tokens, IdentifierMetrics* metrics) {
    metrics->total = 0;
    metrics->unique_count = 0;

    for (int i=0;i<tokens->count;i++) {
        if (is_c_keyword(tokens->tokens[i])) continue;
        if (is_numeric_char(tokens->tokens[i][0])) continue;
        if (is_operator_char(tokens->tokens[i][0])) continue;

        metrics->total++;
        int found = 0;
        for (int j=0;j<metrics->unique_count;j++) {
            if (strcmp(metrics->unique_tokens[j],tokens->tokens[i])==0) {
                found = 1;
                break;
            }
        }
        if (!found && metrics->unique_count<5000) {
            strcpy(metrics->unique_tokens[metrics->unique_count],tokens->tokens[i]);
            metrics->unique_count++;
        }
    }
}
