package DP;
import java.util.List;

class Solution {

    public int minimumTotal(List<List<Integer>> triangle) {
        int m = triangle.size();
        int[] dp = new int[m];
        for(int i =0;i<m;i++){
            dp[i]=triangle.get(m-1).get(i);
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=triangle.get(i).get(j)+Math.min(dp[j],dp[j+1]);
            }
        }

        return dp[0];
        
    }

    public int minimumTotalTab(List<List<Integer>> triangle) {
        int m = triangle.size();
        int n = triangle.get(m-1).size();
        int[][] dp = new int[m][n];
        
        for(int i=0;i<m;i++){
            dp[m-1][i] = triangle.get(m-1).get(i);
        }

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=triangle.get(i).get(j)+Math.min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }

    int solve (int i , int j ,List<List<Integer>> triangle , int dp[][]){
        if(i==triangle.size()-1)
            return triangle.get(i).get(j);
        
        if(i>=triangle.size() || j>i)
            return Integer.MAX_VALUE;

        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=triangle.get(i).get(j)+Math.min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp));

        return dp[i][j];
    }
}