#include "structural_metrics/function.h"
#include <string.h>

int is_function(const char* line) {
    if (strchr(line, '(') && strchr(line, ')') && strchr(line, '{')) {
        if (strstr(line, "if(") || strstr(line, "for(") || strstr(line, "while(") || strstr(line, "switch(")) {
            return 0;
        }
        return 1;
    }
    return 0;
}

void analyze_functions(const FileContent* fileData, FunctionMetrics* metrics) {
    metrics->function_count = 0;
    for (int i = 0; i < fileData->line_count; i++) {
        if (is_function(fileData->lines[i])) {
            metrics->function_count++;
        }
    }
}