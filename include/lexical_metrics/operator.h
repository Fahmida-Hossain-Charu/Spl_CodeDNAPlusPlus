#ifndef OPERATOR_H
#define OPERATOR_H

#include "tokenizer.h"

typedef struct {
    int total;
    int counts[128];
} OperatorMetrics;

void analyze_operators(const TokenList* tokens, OperatorMetrics* metrics);
int get_total_operators(const OperatorMetrics* metrics);

#endif
