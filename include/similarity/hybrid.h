#ifndef HYBRID_H
#define HYBRID_H

#include "tokenizer.h"
#include "cosine.h"
#include "jaccard.h"

double hybrid_similarity(const TokenList* a, const TokenList* b);

#endif
