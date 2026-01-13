#include "similarity/euclidean.h"
#include <math.h>
#include <string.h>

double euclidean_distance(const TokenList* a, const TokenList* b) {
    int vec_a[10000]={0};
    int vec_b[10000]={0};

    for (int i=0;i<a->count;i++)
        for (int j=0;j<b->count;j++)
            if (strcmp(a->tokens[i],b->tokens[j])==0) {
                vec_a[i]++;
                vec_b[j]++;
            }

    double sum=0;
    for (int i=0;i<10000;i++)
        sum += (vec_a[i]-vec_b[i])*(vec_a[i]-vec_b[i]);

    return sqrt(sum);
}