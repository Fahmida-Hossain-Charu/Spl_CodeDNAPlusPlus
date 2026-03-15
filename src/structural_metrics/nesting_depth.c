#include "structural_metrics/nesting_depth.h"
#include <string.h>

void analyze_nesting_depth(const FileContent* fileData, NestingMetrics* metrics) {
    int current_depth = 0;
    int max_depth = 0;
    int total_depth = 0;
    int depth_changes = 0;
    
    for (int i = 0; i < fileData->line_count; i++) {
        const char* line = fileData->lines[i];
        
        for (int j = 0; line[j]; j++) {
            if (line[j] == '{') {
                current_depth++;
                if (current_depth > max_depth) {
                    max_depth = current_depth;
                }
                total_depth += current_depth;
                depth_changes++;
            }
            else if (line[j] == '}') {
                if (current_depth > 0) {
                    current_depth--;
                }
            }
        }
    }
    
    metrics->max_depth = max_depth;
    metrics->avg_depth = depth_changes > 0 ? total_depth / depth_changes : 0;
}