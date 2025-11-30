#ifndef ASCII_OUTPUT_H
#define ASCII_OUTPUT_H

#include "lexical_metrics.h"
#include "structural_metrics.h"

void print_metric_table(LexicalMetrics *lm1, LexicalMetrics *lm2,
                        StructuralMetrics *sm1, StructuralMetrics *sm2);

void print_similarity_bars(float cosine, float euclid, float jaccard, float edit);

#endif
