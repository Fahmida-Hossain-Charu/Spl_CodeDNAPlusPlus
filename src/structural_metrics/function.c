#include "structural_metrics/function.h"
#include <string.h>
#include <ctype.h>

void analyze_functions(const FileContent* fileData, FunctionMetrics* metrics) {
    metrics->total_functions = 0;
    metrics->avg_func_length = 0;
    int lengths[500]={0};
    int cur_length = 0;
    int inside_func = 0;

    for (int i=0;i<fileData->line_count;i++) {
        const char* line = fileData->lines[i];
        int len = strlen(line);
        for (int j=0;j<len;j++) {
            if (!inside_func && line[j]=='{' && j>0) {
                inside_func=1;
                cur_length=1;
            } else if (inside_func && line[j]=='}') {
                inside_func=0;
                if (metrics->total_functions<500) {
                    lengths[metrics->total_functions]=cur_length;
                    metrics->total_functions++;
                }
                cur_length=0;
            }
        }
        if (inside_func) cur_length++;
    }

    int sum=0;
    for (int i=0;i<metrics->total_functions;i++) sum+=lengths[i];
    metrics->avg_func_length = metrics->total_functions>0?sum/metrics->total_functions:0;
}
