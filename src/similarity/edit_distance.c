#include "similarity/edit_distance.h"
#include <string.h>
#include <stdlib.h>

int min3(int a,int b,int c) {
    int m=a<b?a:b;
    return m<c?m:c;
}

int edit_distance(const TokenList* a, const TokenList* b) {
    int n=a->count;
    int m=b->count;
    int** dp = (int**)malloc((n+1)*sizeof(int*));
    for (int i=0;i<=n;i++) dp[i]=(int*)malloc((m+1)*sizeof(int));

    for (int i=0;i<=n;i++) dp[i][0]=i;
    for (int j=0;j<=m;j++) dp[0][j]=j;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            dp[i][j]=min3(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+(strcmp(a->tokens[i-1],b->tokens[j-1])==0?0:1));

    int res=dp[n][m];

    for (int i=0;i<=n;i++) free(dp[i]);
    free(dp);

    return res;
}
