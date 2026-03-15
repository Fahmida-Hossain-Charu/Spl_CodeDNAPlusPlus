#include "file_reader.h"
#include "tokenizer.h"
#include "feature_vector.h"

#include "lexical_metrics/keyword.h"
#include "lexical_metrics/operator.h"
#include "lexical_metrics/identifier.h"
#include "lexical_metrics/comment.h"

#include "structural_metrics/loc.h"
#include "structural_metrics/function.h"
#include "structural_metrics/cyclomatic.h"
#include "structural_metrics/nesting_depth.h"
#include "structural_metrics/statement.h"

#include "similarity/cosine.h"
#include "similarity/euclidean.h"
#include "similarity/jaccard.h"
#include "similarity/edit_distance.h"
#include "similarity/hybrid.h"

#include "ascii_output.h"
#include "config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void analyze_file(const char* filename) {
    FileContent file;
    TokenList tokens;
    
    printf("\nAnalyzing: %s\n", filename);
    printf("====================\n");
    
    if (read_file(filename, &file) != 0) {
        printf("Error: Cannot read file %s\n", filename);
        return;
    }
    
    if (tokenize_file(&file, &tokens) != 0) {
        printf("Error: Cannot tokenize file %s\n", filename);
        return;
    }
    
    KeywordMetrics kw;
    OperatorMetrics op;
    IdentifierMetrics id;
    CommentMetrics cm;
    
    LOCMetrics loc;
    FunctionMetrics func;
    CyclomaticMetrics cyclo;
    NestingMetrics nest;
    StatementMetrics stmt;
    
    analyze_keywords(&tokens, &kw);
    analyze_operators(&tokens, &op);
    analyze_identifiers(&tokens, &id);
    analyze_comments(&file, &cm);
    
    analyze_loc(&file, &loc);
    analyze_functions(&file, &func);
    analyze_cyclomatic(&file, &cyclo);
    analyze_nesting_depth(&file, &nest);
    analyze_statements(&file, &stmt);
    
    print_lexical_metrics(filename, &kw, &op, &id, &cm);
    print_structural_metrics(filename, &loc, &func, &cyclo, &nest, &stmt);
}

void compare_files(const char* file1, const char* file2) {
    FileContent f1, f2;
    TokenList t1, t2;
    
    printf("\nComparing: %s vs %s\n", file1, file2);
    printf("====================\n");
    
    if (read_file(file1, &f1) != 0 || read_file(file2, &f2) != 0) {
        printf("Error: Cannot read files\n");
        return;
    }
    
    if (tokenize_file(&f1, &t1) != 0 || tokenize_file(&f2, &t2) != 0) {
        printf("Error: Cannot tokenize files\n");
        return;
    }
    
    double cosine = cosine_similarity(&t1, &t2);
    double euclid = euclidean_distance(&t1, &t2);
    double jaccard = jaccard_similarity(&t1, &t2);
    double edit = normalized_edit_similarity(&t1, &t2);
    double hybrid = hybrid_similarity(&t1, &t2);
    
    print_similarity(file1, file2, cosine, euclid, jaccard, edit, hybrid);
}

int main(int argc, char* argv[]) {
    printf("\nCodeDNA++ - Code Similarity Analyzer\n");
    printf("====================================\n");
    
    if (argc < 2) {
        printf("\nUsage:\n");
        printf("  %s file.c                    - Analyze single file\n", argv[0]);
        printf("  %s file1.c file2.c            - Compare two files\n", argv[0]);
        printf("  %s file1.c file2.c file3.c    - Compare multiple files\n", argv[0]);
        return 1;
    }
    
    if (argc == 2) {
        analyze_file(argv[1]);
    } 
    else if (argc == 3) {
        analyze_file(argv[1]);
        analyze_file(argv[2]);
        compare_files(argv[1], argv[2]);
    } 
    else {
        for (int i = 1; i < argc; i++) {
            analyze_file(argv[i]);
        }
        
        printf("\nPAIRWISE COMPARISONS\n");
        printf("====================\n");
        for (int i = 1; i < argc; i++) {
            for (int j = i + 1; j < argc; j++) {
                compare_files(argv[i], argv[j]);
            }
        }
    }
    
    return 0;
}