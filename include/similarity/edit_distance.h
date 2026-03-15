#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

#include "tokenizer.h"

int edit_distance(const TokenList* a, const TokenList* b);
double normalized_edit_similarity(const TokenList* a, const TokenList* b);

#endif