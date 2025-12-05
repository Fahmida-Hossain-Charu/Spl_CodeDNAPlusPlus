#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *safe_malloc(size_t size);

char *trim_whitespace(char *str);

void swap_int(int *a, int *b);

#endif
