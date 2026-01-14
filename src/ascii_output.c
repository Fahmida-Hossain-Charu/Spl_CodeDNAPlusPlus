#include "ascii_output.h"
#include <stdio.h>

void print_lexical_metrics(const char* filename, const KeywordMetrics* kw, const OperatorMetrics* op, const IdentifierMetrics* id, const CommentMetrics* cm) {
    printf("Lexical Metrics: %s\n", filename);
    printf("Keywords: %d\n", kw->total);
    printf("Operators: %d\n", op->total);
    printf("Identifiers: %d unique, total %d\n", id->unique_count, id->total);
    printf("Comments: %d single-line, %d block, total %d\n", cm->single_line_count, cm->block_count, cm->total_lines);
    printf("-------------------------------------------------\n");
}

void print_structural_metrics(const char* filename, const LOCMetrics* loc, const FunctionMetrics* func, const CyclomaticMetrics* cyclo, const NestingMetrics* nest, const StatementMetrics* stmt) {
    printf("Structural Metrics: %s\n", filename);
    printf("Total lines: %d, Code lines: %d, Blank lines: %d\n", loc->total_lines, loc->code_lines, loc->blank_lines);
    printf("Functions: %d, Avg func length: %d\n", func->total_functions, func->avg_func_length);
    printf("Cyclomatic complexity: %d\n", cyclo->complexity);
    printf("Max nesting depth: %d\n", nest->max_depth);
    printf("Total statements: %d, Avg statement length: %d\n", stmt->total_statements, stmt->avg_statement_length);
    printf("-------------------------------------------------\n");
}

void print_similarity(const char* fileA, const char* fileB, double cosine, double euclid, double jaccard, double edit, double hybrid) {
    printf("Similarity between %s and %s\n", fileA, fileB);
    printf("Cosine: %.2f\n", cosine);
    printf("Euclidean: %.2f\n", euclid);
    printf("Jaccard: %.2f\n", jaccard);
    printf("Edit distance: %.2f\n", edit);
    printf("Hybrid similarity: %.2f\n", hybrid);
    printf("=================================================\n");
}
