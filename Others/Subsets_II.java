import java.util.List;

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums);
        solve(0, nums, list, ans);
        return ans;
    }

    void solve(int i , int [] nums , List <Integer> list , List<List<Integer>> ans){

        if(i>=nums.length){
            return;
            
        if(i==nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }

        list.add(nums[i]);
        solve(i+1, nums, list, ans);
        list.remove(list.size()-1);
        int number = nums[i];
        while(i<nums.length && nums[i]==number)
        i++;
        solve(i+1, nums, list, ans);
    }
}