#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

int is_c_keyword(const char* word);
int is_operator_char(char c);
int is_identifier_char(char c);
int is_space_or_tab(char c);
int is_numeric_char(char c);
int string_equals(const char* a, const char* b);

void trim_newline(char* str);
void to_lowercase(char* str);

void safe_copy(char* dest, const char* src, int max);
void remove_extra_spaces(char* line);

int count_char_occurrence(const char* line, char c);
int starts_with(const char* text, const char* pattern);
int contains_substring(const char* text, const char* pattern);

void debug_log(const char* message);

#endif
