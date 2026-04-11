#include "similarity/edit_distance.h"
#include <math.h>

double normalized_edit_similarity(const FeatureVector* a, const FeatureVector* b)
{
    double dist = 0.0;

    for (int i = 0; i < 9; i++)
    {
        dist += fabs(a->v[i] - b->v[i]);
    }

    return 1.0 - (dist / 9.0);
}