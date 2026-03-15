#include "lexical_metrics/identifier.h"
#include "utils.h"
#include <string.h>

void analyze_identifiers(const TokenList* tokens, IdentifierMetrics* metrics) {
    metrics->total = 0;
    metrics->unique_count = 0;
    
    for (int i = 0; i < tokens->count; i++) {
        const char* token = tokens->tokens[i];
        
        if (!is_c_keyword(token) && !is_operator_char(token[0]) && 
            (isalpha(token[0]) || token[0] == '_')) {
            
            metrics->total++;
            
            int found = 0;
            for (int j = 0; j < metrics->unique_count; j++) {
                if (strcmp(metrics->unique_tokens[j], token) == 0) {
                    found = 1;
                    break;
                }
            }
            
            if (!found && metrics->unique_count < 5000) {
                strncpy(metrics->unique_tokens[metrics->unique_count], token, 63);
                metrics->unique_tokens[metrics->unique_count][63] = '\0';
                metrics->unique_count++;
            }
        }
    }
}