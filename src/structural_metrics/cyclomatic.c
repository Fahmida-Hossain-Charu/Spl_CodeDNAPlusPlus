#include "structural_metrics/cyclomatic.h"
#include <string.h>

void analyze_cyclomatic(const FileContent* fileData, CyclomaticMetrics* metrics) {
    metrics->complexity = 1;
    const char* patterns[] = {"if","for","while","case","&&","||","?:"};
    int n = sizeof(patterns)/sizeof(patterns[0]);
    
    for (int i = 0; i < fileData->line_count; i++) {
        for (int p = 0; p < n; p++) {
            if (strstr(fileData->lines[i], patterns[p])) {
                metrics->complexity++;
            }
        }
    }
}