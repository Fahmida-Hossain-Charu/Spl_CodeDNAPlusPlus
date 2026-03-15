#ifndef NESTING_DEPTH_H
#define NESTING_DEPTH_H

#include "file_reader.h"

typedef struct {
    int max_depth;
    int avg_depth;
} NestingMetrics;

void analyze_nesting_depth(const FileContent* fileData, NestingMetrics* metrics);

#endif