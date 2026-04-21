#include "structural_metrics/function.h"
#include <string.h>

void analyze_functions(const FileContent* fileData, FunctionMetrics* metrics) {
    metrics->function_count = 0;
    
    for (int i = 0; i < fileData->line_count; i++) {
        const char* line = fileData->lines[i];
        
        
        if (strstr(line, "main(")) continue;
        
        
        if (strstr(line, "if(") || strstr(line, "for(") || 
            strstr(line, "while(") || strstr(line, "switch(")) {
            continue;
        }
        
        
        if (strchr(line, '(') && strchr(line, ')') && strchr(line, '{')) {
            metrics->function_count++;
        }
    }
}