#include "tokenizer.h"
#include "utils.h"
#include <string.h>
#include <ctype.h>

static void push_token(TokenList* list, const char* text) {
    if (!text || strlen(text) == 0) return;
    if (list->count >= 10000) return;
    strncpy(list->tokens[list->count], text, 63);
    list->tokens[list->count][63] = '\0';
    list->count++;
}

static void read_word(const char* line, int* i, char* buffer) {
    int k = 0;
    while (line[*i] && is_identifier_char(line[*i])) {
        buffer[k++] = line[*i];
        (*i)++;
        if (k >= 63) break;
    }
    buffer[k] = '\0';
    (*i)--;
}

static void read_operator(const char* line, int* i, char* buffer) {
    int k = 0;
    while (line[*i] && is_operator_char(line[*i])) {
        buffer[k++] = line[*i];
        (*i)++;
        if (k >= 63) break;
    }
    buffer[k] = '\0';
    (*i)--;
}

static void read_number(const char* line, int* i, char* buffer) {
    int k = 0;
    while (line[*i] && (is_numeric_char(line[*i]) || line[*i]=='.')) {
        buffer[k++] = line[*i];
        (*i)++;
        if (k >= 63) break;
    }
    buffer[k] = '\0';
    (*i)--;
}

static void read_string_literal(const char* line, int* i, char* buffer) {
    int k = 0;
    buffer[k++] = '"';
    (*i)++;
    while (line[*i] && line[*i] != '"') {
        buffer[k++] = line[*i];
        (*i)++;
        if (k >= 62) break;
    }
    buffer[k++] = '"';
    buffer[k] = '\0';
}

static int skip_single_comment(const char* line, int i) {
    while (line[i] && line[i] != '\n') i++;
    return i;
}

static int skip_block_comment(const FileContent* data, int* lineIndex, int start) {
    int i = start + 2;
    while (*lineIndex < data->line_count) {
        const char* line = data->lines[*lineIndex];
        while (line[i]) {
            if (line[i] == '*' && line[i+1] == '/') {
                i += 2;
                return i;
            }
            i++;
        }
        (*lineIndex)++;
        i = 0;
    }
    return i;
}

int tokenize_file(const FileContent* fileData, TokenList* output) {
    output->count = 0;

    for (int l = 0; l < fileData->line_count; l++) {
        const char* line = fileData->lines[l];
        int len = strlen(line);

        for (int i = 0; i < len; i++) {
            char b[128];

            if (is_space_or_tab(line[i])) continue;

            if (line[i] == '/' && line[i+1] == '/') break;

            if (line[i] == '/' && line[i+1] == '*') {
                i = skip_block_comment(fileData, &l, i);
                if (l >= fileData->line_count) break;
                continue;
            }

            if (line[i] == '"') {
                read_string_literal(line, &i, b);
                push_token(output, b);
                continue;
            }

            if (isalpha(line[i]) || line[i]=='_') {
                read_word(line, &i, b);
                push_token(output, b);
                continue;
            }

            if (is_numeric_char(line[i])) {
                read_number(line, &i, b);
                push_token(output, b);
                continue;
            }

            if (is_operator_char(line[i])) {
                read_operator(line, &i, b);
                push_token(output, b);
                continue;
            }

            char tmp[2];
            tmp[0] = line[i];
            tmp[1] = '\0';
            push_token(output, tmp);
        }
    }

    return 0;
}
