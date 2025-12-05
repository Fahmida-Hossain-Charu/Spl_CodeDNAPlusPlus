#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>

// Reads a .c file into a dynamically allocated string
char *read_c_file(const char *filename);

// Counts number of lines in a C file
int count_lines(const char *content);

#endif
