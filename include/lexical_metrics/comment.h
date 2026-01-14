#ifndef COMMENT_H
#define COMMENT_H

#include "file_reader.h"

typedef struct {
    int total_lines;
    int single_line_count;
    int block_count;
} CommentMetrics;

void analyze_comments(const FileContent* fileData, CommentMetrics* metrics);

#endif
