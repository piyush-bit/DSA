#include<stdio.h>

int lcs(char *str1, char *str2, int n, int m , int dp[100][100]) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if(dp[n][m] != -1)
    return dp[n][m];

    if (str1[0] == str2[0]) {
        return 1 + lcs(str1 + 1, str2 + 1, n - 1, m - 1,dp);
    }

    int ans1 = lcs(str1 + 1, str2, n - 1, m , dp);
    int ans2 = lcs(str1, str2 + 1, n, m - 1,dp);

    return ans1 > ans2 ? ans1 : ans2;
}

int main(){
    char str1[100];
    char str2[100];
    char ans[100];

    int dp[100][100];
    for(int i =0 ; i<100 ; i++){
        for(int j =0 ; j<100 ; j++){
            dp[i][j] = -1;
        }
    }

    printf("enter size of first string");
    int n;
    scanf("%d",&n);
    printf("enter first string");
    scanf("%s",str1);
    printf("enter size of second string");
    int m;
    scanf("%d",&m);
    printf("enter string");
    scanf("%s",str2);
    printf("%d",lcs(str1,str2,n,m,dp));
    return 0;
}