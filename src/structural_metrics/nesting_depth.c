#include "structural_metrics/nesting_depth.h"
#include <string.h>

void analyze_nesting_depth(const FileContent* fileData, NestingMetrics* metrics) {
    int current = 0, max = 0, total = 0, count = 0;
    
    for (int i = 0; i < fileData->line_count; i++) {
        const char* line = fileData->lines[i];
        for (int j = 0; line[j]; j++) {
            if (line[j] == '{') {
                current++;
                if (current > max) max = current;
                total += current;
                count++;
            } else if (line[j] == '}') {
                if (current > 0) current--;
            }
        }
    }
    metrics->max_depth = max;
    metrics->avg_depth = count > 0 ? total / count : 0;
}