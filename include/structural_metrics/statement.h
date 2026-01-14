#ifndef STATEMENT_H
#define STATEMENT_H

#include "file_reader.h"

typedef struct {
    int total_statements;
    int avg_statement_length;
} StatementMetrics;

void analyze_statements(const FileContent* fileData, StatementMetrics* metrics);

#endif
