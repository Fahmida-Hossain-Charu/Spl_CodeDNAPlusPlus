#include "tokenizer.h"
#include <string.h>
#include <ctype.h>

static int is_space(char c)
{
    return c==' ' || c=='\t' || c=='\n' || c=='\r';
}

void init_tokenlist(TokenList* t)
{
    t->count = 0;
}

static void push(TokenList* out, const char* buf)
{
    if (!out || out->count >= MAX_TOKENS) return;
    if (strlen(buf) == 0) return;

    strncpy(out->tokens[out->count], buf, MAX_TOKEN_LENGTH - 1);
    out->tokens[out->count][MAX_TOKEN_LENGTH - 1] = '\0';
    out->count++;
}

int tokenize_file(const FileContent* fileData, TokenList* out)
{
    if (!fileData || !out) return -1;

    out->count = 0;

    char buf[64];
    int idx = 0;

    for (int l = 0; l < fileData->line_count; l++)
    {
        const char* s = fileData->lines[l];

        for (int i = 0; s[i]; i++)
        {
            if (isalnum(s[i]) || s[i] == '_')
            {
                buf[idx++] = s[i];
                if (idx >= 63) idx = 63;
            }
            else
            {
                if (idx > 0)
                {
                    buf[idx] = '\0';
                    push(out, buf);
                    idx = 0;
                }

                if (!is_space(s[i]))
                {
                    char op[2] = {s[i], '\0'};
                    push(out, op);
                }
            }
        }

        if (idx > 0)
        {
            buf[idx] = '\0';
            push(out, buf);
            idx = 0;
        }
    }

    return 0;
}