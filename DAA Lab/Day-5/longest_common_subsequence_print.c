#include <stdio.h>
#include <string.h>
#define MAX 100

int dp[MAX][MAX];
int dir[MAX][MAX];
char X[MAX], Y[MAX];
int m, n;

void printLCS(int i, int j, char lcs[], int index) {
    if (i == 0 || j == 0) {
        lcs[index] = '\0';
        for (int k = 0; k < index / 2; k++) {
            char temp = lcs[k];
            lcs[k] = lcs[index - k - 1];
            lcs[index - k - 1] = temp;
        }
        printf("%s\n", lcs);
        return;
    }

    if (dir[i][j] == 1) {
        lcs[index] = X[i - 1];
        printLCS(i - 1, j - 1, lcs, index + 1);
    }
    if (dir[i][j] == 2 || dir[i][j] == 4)
        printLCS(i - 1, j, lcs, index);
    if (dir[i][j] == 3 || dir[i][j] == 4)
        printLCS(i, j - 1, lcs, index);
}

void findLCS() {
    m = strlen(X);
    n = strlen(Y);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 2;
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = 3;
            }
            else {
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 4;
            }
        }
    }
    
    printf("LCS Length: %d\n", dp[m][n]);
    char lcs[MAX];
    printf("All LCSs:\n");
    printLCS(m, n, lcs, 0);
}
char numtocahr(int i ){
    switch (i)
    {
    case  0:
     return '_';
    case 1:
    return '\\';
    case 2:
    return '^';
    case 3:
    return '<';
    case 4:
    return 'v';
    
    default:
        break;
    }

    return '_';
}

void printTable(){
    printf("  \t");
    for(int i = 0 ; i<m ; i++){
        printf("%c \t",X[i]);
    }
    printf("\n\n");
    for(int i = 0 ; i<n ; i++){
        printf("%c \t",Y[i]);
        for(int j = 0 ; j<m ; j++){
            printf("%d%c\t",dp[i+1][j+1],numtocahr(dir[i+1][j+1]) );
        }
        printf("\n\n");
    }
}


void printDir(){

    printf("\n  ");
    for(int i = 0 ; i<m ; i++){
        printf("%c ",X[i]);
    }
    printf("\n");
    for(int i = 0 ; i<n ; i++){
        printf("%c ",Y[i]);
        for(int j = 0 ; j<m ; j++){
            
            printf("%c ",numtocahr(dir[i+1][j+1]));
        }
        printf("\n");
    }
}

int main() {
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);
    findLCS();
    printTable();
    // printDir();
    return 0;
}