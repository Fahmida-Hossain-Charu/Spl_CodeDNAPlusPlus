#include "similarity/hybrid.h"
#include "similarity/cosine.h"
#include "similarity/jaccard.h"

double hybrid_similarity(const TokenList* a, const TokenList* b) {
    double c = cosine_similarity(a, b);
    double j = jaccard_similarity(a, b);

    return (c + j) / 2.0;
}
