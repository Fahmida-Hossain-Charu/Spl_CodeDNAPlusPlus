#include "feature_vector.h"
#include "lexical_metrics/comment.h"
#include "lexical_metrics/identifier.h"
#include "lexical_metrics/keyword.h"
#include "lexical_metrics/operator.h"
#include "structural_metrics/statement.h"
#include "structural_metrics/function.h"
#include "structural_metrics/loc.h"
#include "structural_metrics/cyclomatic.h"
#include "structural_metrics/nesting_depth.h"
#include <math.h>

void build_feature_vector(const FileContent* file,
                          const TokenList* tokens,
                          FeatureVector* fv)
{
    CommentMetrics cm = {0};
    IdentifierMetrics im = {0};
    KeywordMetrics km = {0};
    OperatorMetrics om = {0};
    StatementMetrics sm = {0};
    FunctionMetrics fm = {0};
    LOCMetrics lm = {0};
    CyclomaticMetrics cy = {0};
    NestingMetrics nm = {0};

    analyze_comments(file, &cm);
    analyze_identifiers(tokens, &im);
    analyze_keywords(tokens, &km);
    analyze_operators(tokens, &om);
    analyze_statements(file, &sm);
    analyze_functions(file, &fm);
    analyze_loc(file, &lm);
    analyze_cyclomatic(file, &cy);
    analyze_nesting_depth(file, &nm);

   
    fv->v[0] = (double)fm.function_count;                           
    fv->v[1] = (double)cy.complexity;                                
    fv->v[2] = (double)nm.max_depth;                                 
    fv->v[3] = (double)sm.total_statements / (fm.function_count + 1); 
    fv->v[4] = (double)im.unique_count;                              
    fv->v[5] = (double)lm.code_lines / (fm.function_count + 1);      
    fv->v[6] = (double)cm.total_lines;                               
    fv->v[7] = (double)om.total / (tokens->count + 1);               
    fv->v[8] = (double)km.total / (tokens->count + 1);              
}

void normalize_feature_vector(FeatureVector* fv)
{
   
    double max_vals[] = {5.0, 20.0, 5.0, 30.0, 30.0, 100.0, 10.0, 0.5, 0.5};
    
    for (int i = 0; i < 9; i++) {
        fv->v[i] = fv->v[i] / max_vals[i];
        if (fv->v[i] > 1.0) fv->v[i] = 1.0;
    }
}