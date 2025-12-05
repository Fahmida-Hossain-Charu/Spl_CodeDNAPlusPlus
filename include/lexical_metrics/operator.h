#ifndef OPERATOR_H
#define OPERATOR_H

#include "../tokenizer.h"

// Computes operator density: #operators / total tokens
double compute_operator_density(const TokenList* token_list);

#endif
