#ifndef KEYWORD_H
#define KEYWORD_H

#include "../tokenizer.h"

// Computes keyword density: #keywords / total tokens
double compute_keyword_density(const TokenList* token_list);

#endif
