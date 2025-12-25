#include "utils.h"
#include <string.h>
#include <ctype.h>

void debug_log(const char* message) {
    // printf("[DEBUG] %s\n", message);
}

int is_space_or_tab(char c) {
    return (c == ' ' || c == '\t');
}

int is_numeric_char(char c) {
    return (c >= '0' && c <= '9');
}

int is_identifier_char(char c) {
    if ((c >= 'a' && c <= 'z')) return 1;
    if ((c >= 'A' && c <= 'Z')) return 1;
    if ((c >= '0' && c <= '9')) return 1;
    if (c == '_') return 1;
    return 0;
}

int is_operator_char(char c) {
    switch (c) {
        case '+': case '-': case '*': case '/':
        case '%': case '=': case '>': case '<':
        case '!': case '&': case '|': case '^':
        case '~': case '?': case ':':
            return 1;
        default:
            return 0;
    }
}


int is_c_keyword(const char* word) {
    const char* keywords[] = {
        "int","char","float","double","long","short","void","return",
        "if","else","switch","case","break","continue","for","while",
        "do","struct","union","typedef","enum","const","unsigned",
        "signed","static","sizeof","volatile","extern","register",
        "goto","default","auto","inline","restrict","_Alignas",
        "_Alignof","_Atomic","_Bool","_Complex","_Generic",
        "_Imaginary","_Noreturn","_Static_assert","_Thread_local"
    };

    int total = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < total; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int string_equals(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}


void trim_newline(char* str) {
    if (!str) return;
    int len = strlen(str);
    if (len == 0) return;

    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// Converting everything to lowercase because

void to_lowercase(char* str) {
    if (!str) return;
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower(str[i]);
    }
}

// copying wrapper
void safe_copy(char* dest, const char* src, int max) {
    if (!dest || !src || max <= 0) return;

    strncpy(dest, src, max - 1);
    dest[max - 1] = '\0';
}

// I remove extra spaces so parsing becomes cleaner
void remove_extra_spaces(char* line) {
    if (!line) return;

    char buffer[1024];
    int j = 0;
    int space_seen = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == ' ') {
            if (!space_seen) {
                buffer[j++] = ' ';
                space_seen = 1;
            }
        } else {
            buffer[j++] = line[i];
            space_seen = 0;
        }
    }

    buffer[j] = '\0';
    strcpy(line, buffer);
}

// count a specific char in a line
int count_char_occurrence(const char* line, char c) {
    if (!line) return 0;

    int cnt = 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] == c)
            cnt++;
    }
    return cnt;
}

int starts_with(const char* text, const char* pattern) {
    if (!text || !pattern) return 0;

    int len = strlen(pattern);
    return strncmp(text, pattern, len) == 0;
}

int contains_substring(const char* text, const char* pattern) {
    if (!text || !pattern) return 0;

    return strstr(text, pattern) != NULL;
}
