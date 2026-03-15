#ifndef FUNCTION_METRICS_H
#define FUNCTION_METRICS_H

#include "../file_reader.h"

typedef struct {
    int function_count;
} FunctionMetrics;

void analyze_functions(const FileContent* fileData, FunctionMetrics* metrics);

#endif