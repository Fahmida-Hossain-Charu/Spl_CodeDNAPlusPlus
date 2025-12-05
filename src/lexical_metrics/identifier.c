#include "identifier.h"
#include <string.h>
#include <stdlib.h>

// Count unique identifiers dynamically
int count_unique_identifiers(const TokenList* token_list) {
    if (!token_list) return 0;

    int unique_count = 0;
    int capacity = 1000; // initial capacity
    char** seen = (char**)malloc(sizeof(char*) * capacity);
    for (int i = 0; i < capacity; i++) {
        seen[i] = (char*)malloc(sizeof(char) * MAX_TOKEN_LEN);
        seen[i][0] = '\0';
    }

    for (int i = 0; i < token_list->count; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(token_list->tokens[i], seen[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (unique_count >= capacity) {
                // Double the capacity
                int new_capacity = capacity * 2;
                char** new_seen = (char**)malloc(sizeof(char*) * new_capacity);
                for (int k = 0; k < new_capacity; k++) {
                    new_seen[k] = (char*)malloc(sizeof(char) * MAX_TOKEN_LEN);
                    if (k < capacity)
                        strcpy(new_seen[k], seen[k]);
                    else
                        new_seen[k][0] = '\0';
                }
                for (int k = 0; k < capacity; k++)
                    free(seen[k]);
                free(seen);
                seen = new_seen;
                capacity = new_capacity;
            }
            strcpy(seen[unique_count++], token_list->tokens[i]);
        }
    }

    for (int i = 0; i < capacity; i++)
        free(seen[i]);
    free(seen);

    return unique_count;
}
