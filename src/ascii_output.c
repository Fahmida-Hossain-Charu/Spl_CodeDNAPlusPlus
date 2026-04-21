#include "ascii_output.h"
#include <stdio.h>

void print_lexical_metrics(const char *filename, const KeywordMetrics *kw,
                           const OperatorMetrics *op,
                           const IdentifierMetrics *id,
                           const CommentMetrics *cm)
{

       printf("\n+---------------------------------------------------+\n");
       printf("| LEXICAL METRICS: %-36s |\n", filename);
       printf("+---------------------------------------------------+\n");
       printf("| Keywords: %-41d |\n", kw->total);
       printf("| Operators: %-41d |\n", op->total);
       printf("| Identifiers (total): %-33d |\n", id->total);
       printf("| Identifiers (unique): %-32d |\n", id->unique_count);
       printf("| Single-line comments: %-31d |\n", cm->single_line_count);
       printf("| Block comments: %-36d |\n", cm->block_count);
       printf("| Total comments: %-36d |\n", cm->total_lines);
       printf("+---------------------------------------------------+\n");
}

void print_structural_metrics(const char *filename, const LOCMetrics *loc,
                              const FunctionMetrics *func,
                              const CyclomaticMetrics *cyclo,
                              const NestingMetrics *nest,
                              const StatementMetrics *stmt)
{

       printf("\n+---------------------------------------------------+\n");
       printf("| STRUCTURAL METRICS: %-33s |\n", filename);
       printf("+---------------------------------------------------+\n");
       printf("| Total lines: %-39d |\n", loc->total_lines);
       printf("| Code lines: %-40d |\n", loc->code_lines);
       printf("| Blank lines: %-39d |\n", loc->blank_lines);
       printf("| Functions: %-41d |\n", func->function_count);
       printf("| Cyclomatic complexity: %-30d |\n", cyclo->complexity);
       printf("| Max nesting depth: %-34d |\n", nest->max_depth);
       printf("| Avg nesting depth: %-34d |\n", nest->avg_depth);
       printf("| Total statements: %-34d |\n", stmt->total_statements);
       printf("| Avg statement length: %-31.2f |\n", stmt->avg_statement_length);
       printf("+---------------------------------------------------+\n");
}

void print_similarity(const char *fileA, const char *fileB,
                      double cosine, double euclid,
                      double jaccard, double edit, double hybrid)
{

       printf("\n+=================================================+\n");
       printf("|              SIMILARITY ANALYSIS                 |\n");
       printf("+=================================================+\n");
       printf("| %s vs %s\n", fileA, fileB);
       printf("+-------------------------------------------------+\n");
       printf("| Cosine similarity:  %27.4f |\n", cosine);
       printf("| Euclidean distance: %27.4f |\n", euclid);
       printf("| Jaccard similarity: %27.4f |\n", jaccard);
       printf("| Edit similarity:    %27.4f |\n", edit);
       printf("+-------------------------------------------------+\n");
       printf("| HYBRID SIMILARITY:  %27.4f |\n", hybrid);
       printf("+=================================================+\n");

       printf("\n\nSIMILARITY BAR GRAPH:\n");
       printf("  Cosine  : ");
       for (int i = 0; i < (int)(cosine * 30); i++)
              printf("*");
       printf(" %.2f\n", cosine);

       printf("  Jaccard : ");
       for (int i = 0; i < (int)(jaccard * 30); i++)
              printf("*");
       printf(" %.2f\n", jaccard);

       printf("  Edit    : ");
       for (int i = 0; i < (int)(edit * 30); i++)
              printf("*");
       printf(" %.2f\n", edit);

       printf("  Euclidean: ");
       for (int i = 0; i < (int)((1 - euclid / 10) * 30); i++)
              printf("*");
       printf(" %.2f\n", 1 - euclid / 10);
       printf("  HYBRID  : ");
       for (int i = 0; i < (int)(hybrid * 30); i++)
              printf("*");
       printf(" %.2f\n", hybrid);

       printf("\n===================================================\n");
}