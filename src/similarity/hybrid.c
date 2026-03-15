#include "similarity/hybrid.h"
#include "similarity/cosine.h"
#include "similarity/jaccard.h"
#include "similarity/edit_distance.h"
#include "similarity/euclidean.h"
#include <math.h>

double hybrid_similarity(const TokenList* a, const TokenList* b) {
    double cosine = cosine_similarity(a, b);
    double jaccard = jaccard_similarity(a, b);
    double edit = normalized_edit_similarity(a, b);
    double euclid = 1.0 / (1.0 + euclidean_distance(a, b));
    
    return (cosine + jaccard + edit + euclid) / 4.0;
}