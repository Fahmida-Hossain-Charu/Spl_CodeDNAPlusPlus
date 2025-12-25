#ifndef LOC_H
#define LOC_H

#include "file_reader.h"

typedef struct {
    int total_lines;
    int blank_lines;
    int code_lines;
} LOCMetrics;

void analyze_loc(const FileContent* fileData, LOCMetrics* metrics);

#endif
