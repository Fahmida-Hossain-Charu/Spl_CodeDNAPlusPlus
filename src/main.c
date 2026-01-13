#include "file_reader.h"
#include "tokenizer.h"
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
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc<3) {
        printf("Provide at least two source files.\n");
        return 1;
    }

    FileContent files[argc-1];
    TokenList tokens[argc-1];

    for(int i=1;i<argc;i++) {
        read_file(argv[i], &files[i-1]);
        tokenize_file(&files[i-1], &tokens[i-1]);
    }

    KeywordMetrics kw[argc-1];
    OperatorMetrics op[argc-1];
    IdentifierMetrics id[argc-1];
    CommentMetrics cm[argc-1];

    LOCMetrics loc[argc-1];
    FunctionMetrics func[argc-1];
    CyclomaticMetrics cyclo[argc-1];
    NestingMetrics nest[argc-1];
    StatementMetrics stmt[argc-1];

    for(int i=0;i<argc-1;i++) {
        analyze_keywords(&tokens[i], &kw[i]);
        analyze_operators(&tokens[i], &op[i]);
        analyze_identifiers(&tokens[i], &id[i]);
        analyze_comments(&files[i], &cm[i]);

        analyze_loc(&files[i], &loc[i]);
        analyze_functions(&files[i], &func[i]);
        analyze_cyclomatic(&files[i], &cyclo[i]);
        analyze_nesting(&files[i], &nest[i]);
        analyze_statements(&files[i], &stmt[i]);

        print_lexical_metrics(argv[i+1], &kw[i], &op[i], &id[i], &cm[i]);
        print_structural_metrics(argv[i+1], &loc[i], &func[i], &cyclo[i], &nest[i], &stmt[i]);
    }

    for(int i=0;i<argc-2;i++)
        for(int j=i+1;j<argc-1;j++) {
            double c = cosine_similarity(&tokens[i], &tokens[j]);
            double e = euclidean_distance(&tokens[i], &tokens[j]);
            double jacc = jaccard_similarity(&tokens[i], &tokens[j]);
            double ed = (double)edit_distance(&tokens[i], &tokens[j]);
            double h = hybrid_similarity(&tokens[i], &tokens[j]);

            print_similarity(argv[i+1], argv[j+1], c, e, jacc, ed, h);
        }

    return 0;
}