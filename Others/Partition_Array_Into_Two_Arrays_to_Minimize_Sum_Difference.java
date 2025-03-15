class Solution {
    public int minimumDifference(int[] nums) {
        int sum = 0 ;
        for(int e : nums )
        sum+=e;

        int halfsum = sum/2;

        boolean dp [] [] = new boolean[nums.length][halfsum];
        for(int i = 0 ;i<nums.length;i++)
        dp[i][0]=true;

        dp[0][nums[0]]=true;

        for(int i = 1 ; i<nums.length-1;i++){
            for(int j = 1 ; j<halfsum;j++){
                boolean notTake = dp[i-1][j];
                boolean take = false;
                if(nums[i]<=j)
                take = dp[i-1][j-nums[i]];

                dp[i][j]=take || notTake;
            }

        }

        int max = 0;
        for(int i = halfsum-1;i>=0;i--){
            if(dp[nums.length-1][i]){
                max= i+1;
            }
        }

        return sum-2*max;
    }
}