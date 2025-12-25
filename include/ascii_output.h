#ifndef ASCII_OUTPUT_H
#define ASCII_OUTPUT_H

#include "lexical_metrics/keyword.h"
#include "lexical_metrics/operator.h"
#include "lexical_metrics/identifier.h"
#include "lexical_metrics/comment.h"
#include "structural_metrics/loc.h"
#include "structural_metrics/function.h"
#include "structural_metrics/cyclomatic.h"
#include "structural_metrics/nesting_depth.h"
#include "structural_metrics/statement.h"
#include "similarity/hybrid.h"

void print_lexical_metrics(const char* filename, const KeywordMetrics* kw, const OperatorMetrics* op, const IdentifierMetrics* id, const CommentMetrics* cm);
void print_structural_metrics(const char* filename, const LOCMetrics* loc, const FunctionMetrics* func, const CyclomaticMetrics* cyclo, const NestingMetrics* nest, const StatementMetrics* stmt);
void print_similarity(const char* fileA, const char* fileB, double cosine, double euclid, double jaccard, double edit, double hybrid);

#endif
