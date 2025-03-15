class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int [] ans = new int [nums.length];

        for(int i =0 ; i<nums.length;i++){
            ans[i]=-1;
            int j = i+1;
            int k =-1;
            while(j!=i){
                if(nums[j]>nums[i]){
                    ans[i]=nums[j];
                    k=j;
                    break;
                }
                j=(j+1)%nums.length;
            }

            while(k!=i || i<nums.length){
               ans[i]=nums[k];
               i++;
            }
        }
        return ans;
    }
}