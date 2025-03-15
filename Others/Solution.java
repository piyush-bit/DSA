import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        solve(0, nums, list, ans);
        return ans;
        
    }

    void solve(int i , int [] nums , List <Integer> list , List<List<Integer>> ans){
        if(i==nums.length){
            ans.add(new ArrayList<>(list));  
            return;
        }

        solve(i+1, nums, list, ans);
        list.add(nums[i]);
        solve(+1, nums, list, ans);
        list.remove(list.size()-1);
    }
}