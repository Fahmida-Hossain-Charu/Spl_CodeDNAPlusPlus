#include "ascii_output.h"
#include <stdio.h>

void print_lexical_metrics(const char* filename, const KeywordMetrics* kw,
                          const OperatorMetrics* op,
                          const IdentifierMetrics* id,
                          const CommentMetrics* cm) {

    printf("\n--- Lexical Metrics for %s ---\n", filename);
    printf("Keywords: %d\n", kw->total);
    printf("Operators: %d\n", op->total);
    printf("Identifiers: %d (Unique: %d)\n", id->total, id->unique_count);
    printf("Comments: %d (Single: %d, Block: %d)\n",
           cm->total_lines, cm->single_line_count, cm->block_count);
}

void print_structural_metrics(const char* filename, const LOCMetrics* loc,
                              const FunctionMetrics* func,
                              const CyclomaticMetrics* cyclo,
                              const NestingMetrics* nest,
                              const StatementMetrics* stmt) {

    printf("\n--- Structural Metrics for %s ---\n", filename);
    printf("LOC: %d (Code: %d, Blank: %d)\n",
           loc->total_lines, loc->code_lines, loc->blank_lines);
    printf("Functions: %d\n", func->function_count);
    printf("Cyclomatic Complexity: %d\n", cyclo->complexity);
    printf("Max Nesting: %d, Avg Nesting: %d\n",
           nest->max_depth, nest->avg_depth);
    printf("Statements: %d, Avg Length: %.2f\n",
           stmt->total_statements, stmt->avg_statement_length);
}

void print_similarity(const char* fileA, const char* fileB,
                      double cosine, double euclid,
                      double jaccard, double edit, double hybrid) {

    printf("\n=== Similarity: %s vs %s ===\n", fileA, fileB);
    printf("Cosine similarity: %.4f\n", cosine);
    printf("Euclidean distance: %.4f\n", euclid);
    printf("Jaccard similarity: %.4f\n", jaccard);
    printf("Edit similarity: %.4f\n", edit);
    printf("HYBRID SIMILARITY: %.4f\n", hybrid);
    printf("========================================\n");
}