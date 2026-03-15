#include "ascii_output.h"
#include <stdio.h>
#include <math.h>

void print_lexical_metrics(const char* filename, const KeywordMetrics* kw, 
                          const OperatorMetrics* op, const IdentifierMetrics* id, 
                          const CommentMetrics* cm) {
    printf("\n--- Lexical Metrics: %s ---\n", filename);
    printf("Keywords: %d\n", kw->total);
    printf("Operators: %d\n", op->total);
    printf("Identifiers (unique): %d\n", id->unique_count);
    printf("Identifiers (total): %d\n", id->total);
    printf("Single-line comments: %d\n", cm->single_line_count);
    printf("Block comments: %d\n", cm->block_count);
    printf("Total comments: %d\n", cm->total_lines);
    printf("----------------------------------------\n");
}

void print_structural_metrics(const char* filename, const LOCMetrics* loc, 
                             const FunctionMetrics* func, const CyclomaticMetrics* cyclo, 
                             const NestingMetrics* nest, const StatementMetrics* stmt) {
    printf("\n--- Structural Metrics: %s ---\n", filename);
    printf("Total lines: %d\n", loc->total_lines);
    printf("Code lines: %d\n", loc->code_lines);
    printf("Blank lines: %d\n", loc->blank_lines);
    printf("Functions: %d\n", func->function_count);
    printf("Cyclomatic complexity: %d\n", cyclo->complexity);
    printf("Max nesting depth: %d\n", nest->max_depth);
    printf("Avg nesting depth: %d\n", nest->avg_depth);
    printf("Total statements: %d\n", stmt->total_statements);
    printf("Avg statement length: %.1f\n", stmt->avg_statement_length);
    printf("----------------------------------------\n");
}

void print_similarity(const char* fileA, const char* fileB, double cosine, 
                     double euclid, double jaccard, double edit, double hybrid) {
    printf("\n=== Similarity: %s vs %s ===\n", fileA, fileB);
    printf("Cosine similarity: %.2f\n", cosine);
    printf("Euclidean distance: %.2f\n", euclid);
    printf("Jaccard similarity: %.2f\n", jaccard);
    printf("Edit similarity: %.2f\n", edit);
    printf("HYBRID SIMILARITY: %.2f\n", hybrid);
    printf("========================================\n");
    
    printf("\nSimilarity Graph:\n");
    printf("Cosine  : ");
    for (int i = 0; i < (int)(cosine * 20); i++) printf("*");
    printf(" %.2f\n", cosine);
    
    printf("Jaccard : ");
    for (int i = 0; i < (int)(jaccard * 20); i++) printf("*");
    printf(" %.2f\n", jaccard);
    
    printf("Edit    : ");
    for (int i = 0; i < (int)(edit * 20); i++) printf("*");
    printf(" %.2f\n", edit);
    
    printf("Hybrid  : ");
    for (int i = 0; i < (int)(hybrid * 20); i++) printf("*");
    printf(" %.2f\n", hybrid);
}