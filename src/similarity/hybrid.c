#include "similarity/hybrid.h"

double hybrid_similarity(const TokenList* a, const TokenList* b) {
    double c = cosine_similarity(a,b);
    double e = 1.0/(1.0+euclidean_distance(a,b));
    double j = jaccard_similarity(a,b);
    double ed = 1.0/(1.0+edit_distance(a,b));

    return (c+e+j+ed)/4.0;
}