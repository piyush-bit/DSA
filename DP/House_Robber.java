package DP;
import java.util.Arrays;

class Solution {
    public int robTab(int[] nums) {

        if(nums.length==1)
            return nums[0];
        int dp [] = new int [nums.length];
        Arrays.fill(dp, -1);
        dp[0]=nums[0];
        dp[1]=Math.max(nums[0],nums[1]);
        int i =2 ;
        while(i<nums.length){
            dp[i]=Math.max(dp[i-1], nums[i]+dp[i-2]);
            i++;
        }
        return dp[nums.length-1];


    }

    public int rob(int[] nums) {

        if (nums == null || nums.length == 0) 
            return 0;
        
        if (nums.length == 1) 
            return nums[0];
            
        int prevMax = nums[0];
        int currMax = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            int temp = currMax;
            currMax = Math.max(currMax, nums[i] + prevMax);
            prevMax = temp;
        }
        
        return currMax;
    }

    

    int solve(int[] nums, int i , int dp []){
        if(i>=nums.length)
            return 0;

        if(dp[i]!=-1)
            return dp[i];
        dp[i]=Math.max(solve(nums, i+1,dp), nums[i]+solve(nums, i+2,dp));
        return dp[i];
    }
}