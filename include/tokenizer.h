#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKEN_LEN 64   // Maximum length of a single token

// Dynamic token list structure
typedef struct {
    char** tokens;   // Array of strings
    int count;       // Current number of tokens
    int capacity;    // Total allocated capacity
} TokenList;

// Create a TokenList with given initial capacity
TokenList* create_token_list(int capacity);

// Free memory allocated for a TokenList
void free_token_list(TokenList* list);

// Add a token to the list, resizing if needed
void add_token(TokenList* list, const char* token);

// Tokenize the content of a C file
TokenList* tokenize_file(const char* content);

// Count keyword occurrences
int count_keywords(const TokenList* token_list);

// Count operator occurrences
int count_operators(const TokenList* token_list);

// Count unique identifiers
int count_identifiers(const TokenList* token_list);

// Count comment lines in the content
int count_comments(const char* content);

#endif
