#include "utils.h"

int is_space_or_tab(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int is_identifier_char(char c) {
    return isalnum(c) || c == '_';
}

int is_operator_char(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' ||
            c == '=' || c == '<' || c == '>' || c == '!');
}