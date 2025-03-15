#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][100], int i, int j, char name) {
    if (i == j) {
        printf("%c", name + (i - 1)); // Print matrix name
        return;
    }
    printf("(");
    printOptimalParenthesis(s, i, s[i][j], name);
    printOptimalParenthesis(s, s[i][j] + 1, j, name);
    printf(")");
}

int printTable(int dp [100][100],int n ){
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
           printf("%d\t",dp[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");
    return 0;
}


int matrixChainOrder(int p[], int n) {
    int m[100][100]; 
    int s[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           s[i][j]=0;
        }
    }


    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    // Print the optimal parenthesization
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1, 'A');
    printf("\n");
    printTable(m,n);
    printTable(s,n);
    return m[1][n - 1]; 
}

int main() {
    int arr[] = {1,2,3,4,6}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n));

    return 0;
}
