#include "similarity/hybrid.h"
#include "similarity/cosine.h"
#include "similarity/jaccard.h"
#include "similarity/edit_distance.h"
#include <math.h>

double hybrid_similarity(const TokenList* a, const TokenList* b) {
    double cosine = cosine_similarity(a, b);
    double jaccard = jaccard_similarity(a, b);
    double edit = normalized_edit_similarity(a, b);
    
    return (cosine * 0.4 + jaccard * 0.3 + edit * 0.3);
}