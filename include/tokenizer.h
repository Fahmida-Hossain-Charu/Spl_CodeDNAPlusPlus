#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "file_reader.h"

#define MAX_TOKENS 10000
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int count;
} TokenList;

void init_tokenlist(TokenList* t);
int tokenize_file(const FileContent* fileData, TokenList* out);

#endif