#include "structural_metrics/cyclomatic.h"
#include <string.h>

void analyze_cyclomatic(const FileContent* fileData, CyclomaticMetrics* metrics) {
    metrics->complexity = 1; 
    
    for (int i = 0; i < fileData->line_count; i++) {
        const char* line = fileData->lines[i];
        
        
        if (strstr(line, "if")) metrics->complexity++;
        
       
        if (strstr(line, "for")) metrics->complexity++;
        
       
        if (strstr(line, "while")) metrics->complexity++;
        
      
        if (strstr(line, "case")) metrics->complexity++;
        
       
        if (strstr(line, "&&")) metrics->complexity++;
        if (strstr(line, "||")) metrics->complexity++;
    }
}