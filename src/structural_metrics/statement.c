#include "structural_metrics/statement.h"
#include <string.h>

void analyze_statements(const FileContent* fileData, StatementMetrics* metrics) {
    metrics->total_statements = 0;
    int lengths[5000]={0};
    int stmt_len=0;
    int stmt_idx=0;

    for (int i=0;i<fileData->line_count;i++) {
        const char* line = fileData->lines[i];
        int len = strlen(line);
        for (int j=0;j<len;j++) {
            stmt_len++;
            if (line[j]==';') {
                lengths[stmt_idx++] = stmt_len;
                stmt_len=0;
                metrics->total_statements++;
            }
        }
        if (stmt_len>0 && line[len-1]!=';') stmt_len++;
    }

    int sum=0;
    for (int i=0;i<stmt_idx;i++) sum+=lengths[i];
    metrics->avg_statement_length = stmt_idx>0?sum/stmt_idx:0;
}
