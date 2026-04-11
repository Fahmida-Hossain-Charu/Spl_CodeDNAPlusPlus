#ifndef FILE_READER_H
#define FILE_READER_H

#define MAX_LINES 10000

typedef struct {
    char** lines;
    int line_count;
} FileContent;

void init_filecontent(FileContent* fc);
int read_file(const char* path, FileContent* fc);
void free_filecontent(FileContent* fc);

#endif