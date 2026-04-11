#include "similarity/euclidean.h"
#include <math.h>

double euclidean_distance(const FeatureVector* a, const FeatureVector* b)
{
    double sum = 0;

    for (int i = 0; i < 9; i++)
    {
        double d = a->v[i] - b->v[i];
        sum += d * d;
    }

    return sqrt(sum);
}

double euclidean_similarity(const FeatureVector* a, const FeatureVector* b)
{
    double d = euclidean_distance(a, b);

    
    return exp(-d);
}