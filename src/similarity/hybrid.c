#include "similarity/hybrid.h"
#include "similarity/cosine.h"
#include "similarity/jaccard.h"
#include "similarity/edit_distance.h"
#include "similarity/euclidean.h"

static double clamp(double x)
{
    if (x < 0) return 0;
    if (x > 1) return 1;
    return x;
}

double hybrid_similarity(const FeatureVector* a, const FeatureVector* b)
{
    double c = clamp(cosine_similarity(a, b));
    double j = clamp(jaccard_similarity(a, b));
    double e = clamp(normalized_edit_similarity(a, b));
    double d = clamp(euclidean_similarity(a, b));

    return (c + j + e + d) / 4.0;
}