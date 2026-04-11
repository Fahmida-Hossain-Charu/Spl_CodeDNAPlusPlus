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

void build_feature_vector(const FileContent* file,
                          const TokenList* tokens,
                          FeatureVector* fv)
{
    CommentMetrics cm;
    IdentifierMetrics im;
    KeywordMetrics km;
    OperatorMetrics om;

    StatementMetrics sm;
    FunctionMetrics fm;
    LOCMetrics lm;
    CyclomaticMetrics cy;
    NestingMetrics nm;

    analyze_comments(file, &cm);
    analyze_identifiers(tokens, &im);
    analyze_keywords(tokens, &km);
    analyze_operators(tokens, &om);

    analyze_statements(file, &sm);
    analyze_functions(file, &fm);
    analyze_loc(file, &lm);
    analyze_cyclomatic(file, &cy);
    analyze_nesting_depth(file, &nm);

    fv->v[0] = cm.total_lines;
    fv->v[1] = im.total;
    fv->v[2] = km.total;
    fv->v[3] = om.total;
    fv->v[4] = sm.total_statements;
    fv->v[5] = fm.function_count;
    fv->v[6] = lm.code_lines;
    fv->v[7] = cy.complexity;
    fv->v[8] = nm.max_depth;
}

void normalize_feature_vector(FeatureVector* fv)
{
    double max = fv->v[0];

    for (int i = 1; i < 9; i++)
        if (fv->v[i] > max) max = fv->v[i];

    if (max == 0) max = 1;

    for (int i = 0; i < 9; i++)
        fv->v[i] /= max;
}