#ifndef KEYWORD_H
#define KEYWORD_H

#include "tokenizer.h"

typedef struct {
    int total;
} KeywordMetrics;

void analyze_keywords(const TokenList* tokens, KeywordMetrics* metrics);

#endif