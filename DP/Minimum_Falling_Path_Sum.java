package DP;
import java.util.Arrays;

class Solution {

    public int minFallingPathSum(int[][] matrix){
        //Space Optimization
        int m = matrix.length;
        int n = matrix[0].length;
        int[] dp = new int[n];
        int [] cur = new int [n];
        
        for(int i=0;i<n;i++){
            dp[i] = matrix[m-1][i];
        }
        
        for(int i = m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                cur[j]=matrix[i][j]+Math.min(dp[j],Math.min(j+1<n?dp[j+1]:Integer.MAX_VALUE,j-1>=0?dp[j-1]:Integer.MAX_VALUE));
            }
            //copy array cur in dp
            Arrays.copyOf(cur, n);

        }
        
        int min = Integer.MAX_VALUE;
        for(int i:dp){
            min = Math.min(min,i);
        }
        
        return min;
    }


    public int minFallingPathSumTab(int[][] matrix) {

        int m = matrix.length;
        int n = matrix[0].length;
        int dp[][]=new int[matrix.length][matrix[0].length];
        for(int i=0;i<n;i++){
           dp[m-1][i]=matrix[m-1][i];
        }
        
        for(int i = m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                dp[i][j]=matrix[i][j]+Math.min(dp[i+1][j],Math.min(j+1<n?dp[i+1][j+1]:Integer.MAX_VALUE,j-1>=0?dp[i+1][j-1]:Integer.MAX_VALUE));
            }
        }

        int min = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            min = Math.min(min,dp[0][i]);
        }

        return min;
        
    }

    int solve(int i , int j ,int[][] matrix , int dp[][]){
        int m = matrix.length;
        int n = matrix[0].length;

        if(i<0||j<0||i>=m||j>=n)
            return Integer.MAX_VALUE;
        if(i==m-1 )
            return matrix[i][j];

        if(dp[i][j]!=-1)
            return dp[i][j];

        dp[i][j]=matrix[i][j]+Math.min(solve(i+1,j,matrix,dp),Math.min(solve(i+1,j+1,matrix,dp),solve(i+1,j-1,matrix,dp)));
        return dp[i][j];
    }
}