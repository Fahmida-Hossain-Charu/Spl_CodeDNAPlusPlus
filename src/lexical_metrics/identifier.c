#include "lexical_metrics/identifier.h"
#include "utils.h"
#include <string.h>
#include <ctype.h>

static int is_keyword(const char* w) {
    const char* kw[] = {"int","char","float","double","void","return","if","else","for","while","do","break","continue","switch","case","default","struct","union","typedef","enum","const","static","sizeof"};
    int n = sizeof(kw)/sizeof(kw[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(w, kw[i]) == 0) return 1;
    }
    return 0;
}

void analyze_identifiers(const TokenList* tokens, IdentifierMetrics* metrics) {
    metrics->total = 0;
    metrics->unique_count = 0;
    
    for (int i = 0; i < tokens->count; i++) {
        const char* token = tokens->tokens[i];
        
        if (!is_keyword(token) && !is_operator_char(token[0]) && (isalpha(token[0]) || token[0] == '_')) {
            metrics->total++;
            
            int found = 0;
            for (int j = 0; j < metrics->unique_count; j++) {
                if (strcmp(metrics->unique_tokens[j], token) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found && metrics->unique_count < 5000) {
                strcpy(metrics->unique_tokens[metrics->unique_count], token);
                metrics->unique_count++;
            }
        }
    }
}