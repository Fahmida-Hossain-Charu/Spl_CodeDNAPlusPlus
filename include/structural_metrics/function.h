#ifndef FUNCTION_H
#define FUNCTION_H

#include "file_reader.h"

typedef struct {
    int total_functions;
    int avg_func_length;
} FunctionMetrics;

void analyze_functions(const FileContent* fileData, FunctionMetrics* metrics);

#endif
