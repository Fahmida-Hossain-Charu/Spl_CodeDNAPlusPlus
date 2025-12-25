#include "similarity/jaccard.h"
#include <string.h>

double jaccard_similarity(const TokenList* a, const TokenList* b) {
    int intersection=0;
    int union_count=a->count+b->count;

    for (int i=0;i<a->count;i++)
        for (int j=0;j<b->count;j++)
            if (strcmp(a->tokens[i],b->tokens[j])==0) intersection++;

    return union_count==0?0.0:(double)intersection/(union_count-intersection);
}
