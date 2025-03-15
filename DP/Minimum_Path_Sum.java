package DP;
class Solution {

    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] dp = new int[n];
        dp[0] = grid[0][0];
        
        // Initialize the first row
        for (int i = 1; i < n; i++) {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        
        // Update the dp array iteratively
        for (int i = 1; i < m; i++) {
            // Update the first column
            dp[0] += grid[i][0];
            
            // Update the rest of the row
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + Math.min(dp[j], dp[j - 1]);
            }
        }
        
        return dp[n - 1];
    }
    public int minPathSumTab(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int dp[][]=new int[grid.length][grid[0].length];
        dp[0][0]=grid[0][0];
        //initialize top row
        for(int i=1;i<m;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        //innitialize left column
        for(int i=1;i<n;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+Math.min(dp[i-1][j],dp[i][j-1]);
            }
        }


        return dp[m-1][n-1];
        
    }
        int solve(int i , int j ,int[][] grid , int dp[][] ){
            int m = grid.length;
            int n = grid[0].length;

            if(i==m-1 && j==n-1)
                return grid[i][j];
        
        if(i>=m || j>=n)
            return Integer.MAX_VALUE;

        if(dp[i][j]!=-1)
            return dp[i][j];

        dp[i][j]=grid[i][j]+Math.min(solve(i+1,j,grid,dp),solve(i,j+1,grid,dp));
        return dp[i][j];
    }
}