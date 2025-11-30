#ifndef LEXICAL_METRICS_H
#define LEXICAL_METRICS_H

typedef struct {
    float keyword_density;
    float operator_usage;
    float identifier_diversity;
    float comment_ratio;
} LexicalMetrics;

LexicalMetrics compute_lexical_metrics(const char *code);

#endif
