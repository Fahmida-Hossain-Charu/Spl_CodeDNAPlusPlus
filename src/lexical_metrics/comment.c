#include "lexical_metrics/comment.h"
#include <string.h>

void analyze_comments(const FileContent* fileData, CommentMetrics* metrics) {
    metrics->total_lines = 0;
    metrics->single_line_count = 0;
    metrics->block_count = 0;

    int in_block = 0;

    for (int i=0;i<fileData->line_count;i++) {
        const char* line = fileData->lines[i];
        int len = strlen(line);

        for (int j=0;j<len;j++) {
            if (!in_block && line[j]=='/' && line[j+1]=='/') {
                metrics->single_line_count++;
                break;
            }
            if (!in_block && line[j]=='/' && line[j+1]=='*') {
                metrics->block_count++;
                in_block=1;
                j++;
            } else if (in_block && line[j]=='*' && line[j+1]=='/') {
                in_block=0;
                j++;
            }
        }
    }

    metrics->total_lines = metrics->single_line_count + metrics->block_count;
}
