#ifndef OPERATOR_H
#define OPERATOR_H

#include "tokenizer.h"

typedef struct {
    int total;
} OperatorMetrics;

void analyze_operators(const TokenList* tokens, OperatorMetrics* metrics);

#endif