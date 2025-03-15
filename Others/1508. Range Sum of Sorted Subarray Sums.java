import java.util.Arrays;

class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int sums [] = new int[n*(n+1)/2];
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                sums[index] = i==j ? nums[i] : sums[index-1]+nums[i];
                index++;
            }
        }
        Arrays .sort(sums);
        int ans = 0;
        for(int i = left-1 ; i < right ; i++){
            ans += sums[i];
        }
        return ans;
    }

    public int sum(int [] nums , int i , int j){
        int sum = 0;
        for(int k = i ; k <= j ; k++){
            sum += nums[k];
        }
        return sum;
    }
}

