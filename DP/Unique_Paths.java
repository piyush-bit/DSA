package DP;
class Solution {
    public int uniquePaths(int m, int n) {

        int dp[][] = new int [m][n];
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        for(int i=0;i<n;i++){
            dp[m-1][i]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];


    }
    int solve(int i , int j , int m ,int n,int dp[][]){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
        return dp[i][j];
    }
}