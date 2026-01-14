#include "structural_metrics/loc.h"
#include <string.h>

void analyze_loc(const FileContent* fileData, LOCMetrics* metrics) {
    metrics->total_lines = fileData->line_count;
    metrics->blank_lines = 0;
    metrics->code_lines = 0;

    for (int i=0;i<fileData->line_count;i++) {
        int empty = 1;
        for (int j=0;fileData->lines[i][j];j++) {
            if (fileData->lines[i][j]!=' ' && fileData->lines[i][j]!='\t') {
                empty = 0;
                break;
            }
        }
        if (empty) metrics->blank_lines++;
        else metrics->code_lines++;
    }
}
