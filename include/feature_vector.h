#ifndef FEATURE_VECTOR_H
#define FEATURE_VECTOR_H

#include "file_reader.h"
#include "tokenizer.h"

typedef struct {
    double v[9];
} FeatureVector;

void build_feature_vector(const FileContent* file,
                          const TokenList* tokens,
                          FeatureVector* fv);

void normalize_feature_vector(FeatureVector* fv);

#endif