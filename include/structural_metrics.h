#ifndef STRUCTURAL_METRICS_H
#define STRUCTURAL_METRICS_H

typedef struct {
    int line_count;
    int function_count;
    int cyclomatic_complexity;
    int max_depth;
    float avg_stmt_length;
} StructuralMetrics;

StructuralMetrics compute_structural_metrics(const char *code);

#endif
