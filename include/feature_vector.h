#ifndef FEATURE_VECTOR_H
#define FEATURE_VECTOR_H

#include "file_reader.h"
#include "tokenizer.h"
#include "lexical_metrics/keyword.h"
#include "lexical_metrics/operator.h"
#include "lexical_metrics/identifier.h"
#include "lexical_metrics/comment.h"
#include "structural_metrics/loc.h"
#include "structural_metrics/function.h"
#include "structural_metrics/cyclomatic.h"
#include "structural_metrics/nesting_depth.h"
#include "structural_metrics/statement.h"

void build_feature_vector(const FileContent* file, const TokenList* tokens, 
                          double* vector, int* vector_size);

#endif