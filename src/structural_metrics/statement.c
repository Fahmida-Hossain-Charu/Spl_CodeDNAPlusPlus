#include "structural_metrics/statement.h"
#include <string.h>

void analyze_statements(const FileContent* fileData, StatementMetrics* metrics) {
    int total_statements = 0;
    int total_chars = 0;
    int function_count = 0;
    int in_function = 0;
    
    for (int i = 0; i < fileData->line_count; i++) {
        const char* line = fileData->lines[i];
        
        
        if (strchr(line, '{') && !strstr(line, "main(")) {
            in_function = 1;
            function_count++;
            continue;
        }
        
       
        if (in_function) {
            int len = strlen(line);
            for (int j = 0; j < len; j++) {
                if (line[j] == ';') {
                    total_statements++;
                    total_chars += len;
                    break;
                }
            }
        }
        
       
        if (in_function && strchr(line, '}')) {
            in_function = 0;
        }
    }
    
    metrics->total_statements = total_statements;
    metrics->avg_statement_length = (total_statements > 0) ? 
                                    (double)total_chars / total_statements : 0;
}