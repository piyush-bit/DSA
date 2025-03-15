package DP;
import java.util.Arrays;

class Solution {

    // public boolean canPartition(int[] nums) {
    //    //TODO : Implement tabulation
       

    // }
    public boolean canPartitionMemo(int[] nums) {
       int sum = 0;
       for(int e : nums ){
        sum+=e;
       }
       if(sum%2==1)
       return false;
       int [][] dp = new int [nums.length][sum/2+1];
       for(int i=0;i<nums.length;i++){
        Arrays.fill(dp[i], -1);
       }
       return solve(0, nums, sum/2 , dp);
    }

    boolean solve(int i , int [] nums , int sum , int [][] dp){
        if(sum<0)
        return false;

        if(i==nums.length){
            if(sum==0)
                return true;
            else
                return false;
        }

        if(dp[i][sum]!=-1)
        return dp[i][sum]==1;

        dp[i][sum] = solve(i+1, nums, sum-nums[i], dp) || solve(i+1, nums, sum , dp) ? 1:0;
        return dp[i][sum]==1;
    }
}