#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>

typedef struct {
    char lines[5000][512];
    int line_count;
} FileContent;

int read_file(const char* path, FileContent* fileData);

#endif
