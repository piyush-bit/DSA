package DP;
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        int[][] dp = new int[m][n];
        
        // Base case: if the starting point is an obstacle, then there is no way to reach the destination
        if (obstacleGrid[0][0] == 1) 
            return 0;
        
        // Initialize the starting point
        dp[0][0] = 1;
        
        // Initialize the first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1)
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j - 1];
        }
        
        // Initialize the first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 1][0];
        }
        
        // Fill up the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
    

    int solve (int i , int j ,int[][] obstacleGrid , int dp[][] ){
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if(i>=m || j>=n || obstacleGrid[i][j]==1)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;

        if(dp[i][j]!=-1)
            return dp[i][j];   

        dp[i][j]=solve(i+1,j,obstacleGrid,dp)+solve(i,j+1,obstacleGrid,dp);
        return dp[i][j];
    }
}