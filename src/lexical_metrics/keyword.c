#include "lexical_metrics/keyword.h"
#include "utils.h"
#include <string.h>

static const char* keyword_list[] = {
    "int","char","float","double","long","short","void","return",
    "if","else","switch","case","break","continue","for","while",
    "do","struct","union","typedef","enum","const","unsigned",
    "signed","static","sizeof","volatile","extern","register",
    "goto","default","auto","inline","restrict","_Alignas",
    "_Alignof","_Atomic","_Bool","_Complex","_Generic",
    "_Imaginary","_Noreturn","_Static_assert","_Thread_local"
};

static int is_keyword(const char* w) {
    int total = sizeof(keyword_list)/sizeof(keyword_list[0]);
    for (int i=0;i<total;i++) {
        if (strcmp(w,keyword_list[i])==0) return 1;
    }
    return 0;
}

void analyze_keywords(const TokenList* tokens, KeywordMetrics* metrics) {
    metrics->total = 0;
    memset(metrics->counts,0,sizeof(metrics->counts));

    for (int i=0;i<tokens->count;i++) {
        if (is_keyword(tokens->tokens[i])) {
            int idx = tokens->tokens[i][0]%128;
            metrics->counts[idx]++;
            metrics->total++;
        }
    }
}

int get_total_keywords(const KeywordMetrics* metrics) {
    return metrics->total;
}
