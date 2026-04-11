#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H

#include "feature_vector.h"

double euclidean_distance(const FeatureVector* a, const FeatureVector* b);
double euclidean_similarity(const FeatureVector* a, const FeatureVector* b);

#endif