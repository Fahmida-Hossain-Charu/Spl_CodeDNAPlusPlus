#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

#include "feature_vector.h"

double normalized_edit_similarity(const FeatureVector* a, const FeatureVector* b);

#endif