#ifndef CYCLOMATIC_H
#define CYCLOMATIC_H

#include "file_reader.h"

typedef struct {
    int complexity;
} CyclomaticMetrics;

void analyze_cyclomatic(const FileContent* fileData, CyclomaticMetrics* metrics);

#endif
