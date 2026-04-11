#include "similarity/cosine.h"
#include <math.h>

double cosine_similarity(const FeatureVector* a, const FeatureVector* b)
{
    double dot = 0.0;
    double magA = 0.0;
    double magB = 0.0;

    for (int i = 0; i < 9; i++)
    {
        dot += a->v[i] * b->v[i];
        magA += a->v[i] * a->v[i];
        magB += b->v[i] * b->v[i];
    }

    if (magA == 0 || magB == 0)
        return 0.0;

    return dot / (sqrt(magA) * sqrt(magB));
}