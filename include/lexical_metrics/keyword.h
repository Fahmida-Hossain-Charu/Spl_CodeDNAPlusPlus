#ifndef KEYWORD_H
#define KEYWORD_H

#include "tokenizer.h"

typedef struct {
    int total;
    int counts[128];
} KeywordMetrics;

void analyze_keywords(const TokenList* tokens, KeywordMetrics* metrics);
int get_total_keywords(const KeywordMetrics* metrics);

#endif
