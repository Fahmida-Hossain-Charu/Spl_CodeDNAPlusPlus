#ifndef HYBRID_H
#define HYBRID_H

#include "cosine.h"
#include "euclidean.h"
#include "jaccard.h"
#include "edit_distance.h"

double hybrid_similarity(const TokenList* a, const TokenList* b);

#endif
