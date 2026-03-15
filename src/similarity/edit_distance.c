#include "similarity/edit_distance.h"
#include <string.h>
#include <stdlib.h>

int edit_distance(const TokenList* a, const TokenList* b) {
    int n = a->count;
    int m = b->count;
    
    int dp[1000][1000];
    
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (strcmp(a->tokens[i-1], b->tokens[j-1]) == 0) ? 0 : 1;
            
            int del = dp[i-1][j] + 1;
            int ins = dp[i][j-1] + 1;
            int sub = dp[i-1][j-1] + cost;
            
            int min = del;
            if (ins < min) min = ins;
            if (sub < min) min = sub;
            
            dp[i][j] = min;
        }
    }
    
    return dp[n][m];
}

double normalized_edit_similarity(const TokenList* a, const TokenList* b) {
    int distance = edit_distance(a, b);
    int max_len = a->count > b->count ? a->count : b->count;
    
    if (max_len == 0) return 1.0;
    return 1.0 - ((double)distance / max_len);
}