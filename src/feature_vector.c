#include "feature_vector.h"
#include <string.h>
#include <stdio.h>

void build_feature_vector(const FileContent* file, const TokenList* tokens, 
                          double* vector, int* vector_size) {
    KeywordMetrics kw;
    OperatorMetrics op;
    IdentifierMetrics id;
    CommentMetrics cm;
    LOCMetrics loc;
    FunctionMetrics func;
    CyclomaticMetrics cyclo;
    NestingMetrics nest;
    StatementMetrics stmt;
    
    analyze_keywords(tokens, &kw);
    analyze_operators(tokens, &op);
    analyze_identifiers(tokens, &id);
    analyze_comments(file, &cm);
    analyze_loc(file, &loc);
    analyze_functions(file, &func);
    analyze_cyclomatic(file, &cyclo);
    analyze_nesting_depth(file, &nest);
    analyze_statements(file, &stmt);
    
    vector[0] = kw.total / 100.0;
    vector[1] = op.total / 100.0;
    vector[2] = id.unique_count / 100.0;
    vector[3] = cm.total_lines / 100.0;
    vector[4] = loc.code_lines / 1000.0;
    vector[5] = func.function_count / 50.0;
    vector[6] = cyclo.complexity / 50.0;
    vector[7] = nest.max_depth / 10.0;
    vector[8] = stmt.avg_statement_length / 50.0;
    
    *vector_size = 9;
}