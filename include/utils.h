#ifndef UTILS_H
#define UTILS_H

int is_keyword(const char *word);
int is_operator(char c);
int is_identifier_start(char c);
int is_identifier_char(char c);
int string_length(const char *s);

#endif