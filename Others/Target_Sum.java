class Solution {
    public int findTargetSumWays(int[] nums, int target) {

        int dp [][] = new int [nums.length][2001];
        for(int i=0;i<nums.length;i++){
            Arrays.fill(dp[i], -1);
        }
        
        return solve(0,target,nums,nums[0],dp)+solve(0,target,nums,-nums[0],dp);
    }

    int solve (int i , int target , int [] nums, int sum , int [][] dp){
        if(i==nums.length){
            if(sum==target)
                return 1;
            else
                return 0;
        }

        if(dp[i][sum+1000]!=-1)
            return dp[i][sum+1000];

        dp[i][sum+1000]=solve(i+1,target,nums,sum-nums[i],dp)+solve(i+1,target,nums,sum+nums[i],dp);
        return dp[i][sum+1000];
    }

}
