#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "file_reader.h"

typedef struct {
    char tokens[10000][64];
    int count;
} TokenList;

int tokenize_file(const FileContent* fileData, TokenList* output);

#endif
