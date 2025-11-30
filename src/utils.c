#include <ctype.h>
// #include "utils.h"
#include "../include/utils.h"

int is_keyword(const char *word)
{
    const char *kw[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    int i;
    for (i = 0; i < 32; i++)
    {
        const char *p = word;
        const char *q = kw[i];
        int ok = 1;

        while (*p && *q)
        {
            if (*p != *q)
            {
                ok = 0;
                break;
            }
            p++;
            q++;
        }

        if (ok && *p == 0 && *q == 0)
        {
            return 1;
        }
    }

    return 0;
}

int is_operator(char c)
{
    // char ops[] = "+-*/=%<>&|!";
    const char ops[] = "+-*/=%<>&|!";

    int i = 0;

    while (ops[i] != 0)
    {
        if (ops[i] == c)
        {
            return 1;
        }
        i++;
    }

    return 0;
}

int is_identifier_start(char c)
{
    if (isalpha((unsigned char)c) || c == '_')
    {
        return 1;
    }
    return 0;
}

int is_identifier_char(char c)
{
    if (isalnum((unsigned char)c) || c == '_')
    {
        return 1;
    }
    return 0;
}

int string_length(const char *s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}
