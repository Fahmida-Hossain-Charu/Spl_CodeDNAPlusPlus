#include "lexical_metrics/keyword.h"
#include <string.h>

static const char* keywords[] = {
    "int","char","float","double","long","short","void","return",
    "if","else","switch","case","break","continue","for","while",
    "do","struct","union","typedef","enum","const","unsigned",
    "signed","static","sizeof","volatile","extern","register",
    "goto","default","auto","inline","restrict"
};

static int is_keyword(const char* w) {
    int total = sizeof(keywords)/sizeof(keywords[0]);
    for (int i = 0; i < total; i++) {
        if (strcmp(w, keywords[i]) == 0) return 1;
    }
    return 0;
}

void analyze_keywords(const TokenList* tokens, KeywordMetrics* metrics) {
    metrics->total = 0;
    for (int i = 0; i < tokens->count; i++) {
        if (is_keyword(tokens->tokens[i])) {
            metrics->total++;
        }
    }
}