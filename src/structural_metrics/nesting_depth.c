#include "structural_metrics/nesting_depth.h"
#include <string.h>

void analyze_nesting(const FileContent* fileData, NestingMetrics* metrics) {
    metrics->max_depth = 0;
    int current=0;

    for (int i=0;i<fileData->line_count;i++) {
        const char* line = fileData->lines[i];
        int len = strlen(line);
        for (int j=0;j<len;j++) {
            if (line[j]=='{') current++;
            else if (line[j]=='}') current--;
            if (current>metrics->max_depth) metrics->max_depth=current;
        }
    }
}
