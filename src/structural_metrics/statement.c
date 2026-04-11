#include "structural_metrics/statement.h"
#include <string.h>

void analyze_statements(const FileContent* fileData, StatementMetrics* metrics) {
    metrics->total_statements = 0;
    int total_chars = 0;
    
    for (int i = 0; i < fileData->line_count; i++) {
        const char* line = fileData->lines[i];
        int len = strlen(line);
        for (int j = 0; j < len; j++) {
            if (line[j] == ';' || line[j] == '{' || line[j] == '}') {
                metrics->total_statements++;
                total_chars += len;
                break;
            }
        }
    }
    metrics->avg_statement_length = metrics->total_statements > 0 ? (double)total_chars / metrics->total_statements : 0;
}