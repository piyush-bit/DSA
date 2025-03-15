#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lcs(char *str1, char *str2, int n, int m, char *dp[100][100]) {
    if (n == 0 || m == 0) {
        char *emptyStr = (char *)malloc(1);
        emptyStr[0] = '\0';
        return emptyStr;
    }

    if (dp[n][m] != NULL)
        return dp[n][m];

    if (str1[0] == str2[0]) {
        char *l = lcs(str1 + 1, str2 + 1, n - 1, m - 1, dp);
        char *ptr = (char *)malloc(strlen(l) + 2); 
        ptr[0] = str1[0]; 
        strcpy(ptr + 1, l);
        dp[n][m] = ptr;
        // free(l); 
        return ptr;
    }

    char *ans1 = lcs(str1 + 1, str2, n - 1, m, dp);
    char *ans2 = lcs(str1, str2 + 1, n, m - 1, dp);

    if (strlen(ans1) > strlen(ans2)) {
        dp[n][m] = (char *)malloc(strlen(ans1) + 1);
        strcpy(dp[n][m], ans1);
    } else {
        dp[n][m] = (char *)malloc(strlen(ans2) + 1);
        strcpy(dp[n][m], ans2);
    }

    // free(ans1);
    // free(ans2);

    return dp[n][m];
}

int main() {
    char str1[100], str2[100];
    char *dp[100][100] = {NULL};  

    int n, m;
    printf("Enter size of first string: ");
    scanf("%d", &n);
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter size of second string: ");
    scanf("%d", &m);
    printf("Enter second string: ");
    scanf("%s", str2);

    char *result = lcs(str1, str2, n, m, dp);
    printf("Longest Common Subsequence: %s\n", result);
    
    free(result);  // Free memory allocated for result
    return 0;

    for(int i = 0 ; i<=n ; i++){
        for(int j = 0; i<=m ; j++ ){
            
        }
    }
    return dp[n][m];
}
