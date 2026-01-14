#include "similarity/cosine.h"
#include <math.h>
#include <string.h>

double cosine_similarity(const TokenList* a, const TokenList* b) {
    int vec_a[10000]={0};
    int vec_b[10000]={0};

    for (int i=0;i<a->count;i++) {
        for (int j=0;j<b->count;j++) {
            if (strcmp(a->tokens[i],b->tokens[j])==0) {
                vec_a[i]++;
                vec_b[j]++;
            }
        }
    }

    double dot=0,sq_a=0,sq_b=0;
    for (int i=0;i<10000;i++) {
        dot += vec_a[i]*vec_b[i];
        sq_a += vec_a[i]*vec_a[i];
        sq_b += vec_b[i]*vec_b[i];
    }

    return (sq_a==0||sq_b==0)?0.0:dot/(sqrt(sq_a)*sqrt(sq_b));
}
