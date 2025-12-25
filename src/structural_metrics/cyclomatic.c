#include "structural_metrics/cyclomatic.h"
#include <string.h>

void analyze_cyclomatic(const FileContent* fileData, CyclomaticMetrics* metrics) {
    metrics->complexity = 1;

    const char* keywords[] = {"if","for","while","case","&&","||","?:"};
    int ktotal = sizeof(keywords)/sizeof(keywords[0]);

    for (int i=0;i<fileData->line_count;i++) {
        const char* line = fileData->lines[i];
        for (int k=0;k<ktotal;k++) {
            if (strstr(line,keywords[k])) metrics->complexity++;
        }
    }
}
