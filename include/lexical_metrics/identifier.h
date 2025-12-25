#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "tokenizer.h"

typedef struct {
    int total;
    char unique_tokens[5000][64];
    int unique_count;
} IdentifierMetrics;

void analyze_identifiers(const TokenList* tokens, IdentifierMetrics* metrics);

#endif
