#include "similarity/euclidean.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

double euclidean_distance(const TokenList* a, const TokenList* b) {
    typedef struct {
        char token[64];
        int freq_a;
        int freq_b;
    } TokenFreq;
    
    TokenFreq freqs[2000];
    int freq_count = 0;
    
    for (int i = 0; i < a->count; i++) {
        int found = 0;
        for (int j = 0; j < freq_count; j++) {
            if (strcmp(freqs[j].token, a->tokens[i]) == 0) {
                freqs[j].freq_a++;
                found = 1;
                break;
            }
        }
        if (!found && freq_count < 2000) {
            strcpy(freqs[freq_count].token, a->tokens[i]);
            freqs[freq_count].freq_a = 1;
            freqs[freq_count].freq_b = 0;
            freq_count++;
        }
    }
    
    for (int i = 0; i < b->count; i++) {
        int found = 0;
        for (int j = 0; j < freq_count; j++) {
            if (strcmp(freqs[j].token, b->tokens[i]) == 0) {
                freqs[j].freq_b++;
                found = 1;
                break;
            }
        }
        if (!found && freq_count < 2000) {
            strcpy(freqs[freq_count].token, b->tokens[i]);
            freqs[freq_count].freq_a = 0;
            freqs[freq_count].freq_b = 1;
            freq_count++;
        }
    }
    
    double sum = 0.0;
    for (int i = 0; i < freq_count; i++) {
        double diff = freqs[i].freq_a - freqs[i].freq_b;
        sum += diff * diff;
    }
    
    return sqrt(sum);
}