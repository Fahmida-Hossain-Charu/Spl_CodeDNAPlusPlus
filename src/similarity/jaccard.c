#include "similarity/jaccard.h"

double jaccard_similarity(const FeatureVector* a, const FeatureVector* b)
{
    double inter = 0.0;
    double uni = 0.0;

    for (int i = 0; i < 9; i++)
    {
        double maxv = (a->v[i] > b->v[i]) ? a->v[i] : b->v[i];
        double minv = (a->v[i] < b->v[i]) ? a->v[i] : b->v[i];

        inter += minv;
        uni += maxv;
    }

    if (uni == 0) return 0.0;

    return inter / uni;
}