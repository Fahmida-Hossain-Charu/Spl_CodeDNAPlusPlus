#include "file_reader.h"
#include "tokenizer.h"

#include "lexical_metrics/keyword.h"
#include "lexical_metrics/operator.h"
#include "lexical_metrics/identifier.h"
#include "lexical_metrics/comment.h"

#include "structural_metrics/loc.h"
#include "structural_metrics/cyclomatic.h"

#include "similarity/cosine.h"
#include "similarity/jaccard.h"
#include "similarity/hybrid.h"

#include <stdio.h>
#include <string.h>

void analyze_two_files() {
    char file1[256], file2[256];

    printf("Enter first file: ");
    scanf("%s", file1);
    printf("Enter second file: ");
    scanf("%s", file2);

    FileContent files[2];
    TokenList tokens[2];

    read_file(file1, &files[0]);
    read_file(file2, &files[1]);

    tokenize_file(&files[0], &tokens[0]);
    tokenize_file(&files[1], &tokens[1]);

    KeywordMetrics kw[2];
    OperatorMetrics op[2];
    CommentMetrics cm[2];

    LOCMetrics loc[2];
    CyclomaticMetrics cyclo[2];

    /* File 1 analysis */
    analyze_keywords(&tokens[0], &kw[0]);
    analyze_operators(&tokens[0], &op[0]);
    analyze_comments(&files[0], &cm[0]);
    analyze_loc(&files[0], &loc[0]);
    analyze_cyclomatic(&files[0], &cyclo[0]);

    /* File 2 analysis */
    analyze_keywords(&tokens[1], &kw[1]);
    analyze_operators(&tokens[1], &op[1]);
    analyze_comments(&files[1], &cm[1]);
    analyze_loc(&files[1], &loc[1]);
    analyze_cyclomatic(&files[1], &cyclo[1]);

    /* Output metrics */
    printf("\nLexical Metrics: %s\n", file1);
    printf("  Keywords: %d\n", kw[0].total);
    printf("  Operators: %d\n", op[0].total);
    printf("  Comments: %d\n", cm[0].total_lines);

    printf("\nStructural Metrics: %s\n", file1);
    printf("  LOC (code lines): %d\n", loc[0].code_lines);
    printf("  Cyclomatic Complexity: %d\n", cyclo[0].complexity);

    printf("\nLexical Metrics: %s\n", file2);
    printf("  Keywords: %d\n", kw[1].total);
    printf("  Operators: %d\n", op[1].total);
    printf("  Comments: %d\n", cm[1].total_lines);

    printf("\nStructural Metrics: %s\n", file2);
    printf("  LOC (code lines): %d\n", loc[1].code_lines);
    printf("  Cyclomatic Complexity: %d\n", cyclo[1].complexity);

    /* Similarity calculations */
    double cosine = cosine_similarity(&tokens[0], &tokens[1]);
    double jaccard = jaccard_similarity(&tokens[0], &tokens[1]);
    double hybrid = hybrid_similarity(&tokens[0], &tokens[1]);

    printf("\nSimilarity between %s and %s:\n", file1, file2);
    printf("  Cosine: %.2f\n", cosine);
    printf("  Jaccard: %.2f\n", jaccard);
    printf("  Hybrid (Cosine + Jaccard): %.2f\n", hybrid);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Code Analysis Tool ===\n");
        printf("1. Analyze two files\n");
        printf("2. Analyze a folder (not implemented)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                analyze_two_files();
                break;
            case 2:
                printf("Folder analysis not implemented in mid-demo.\n");
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
