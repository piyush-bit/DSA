import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        solve(0, candidates, target, list, ans);
        return ans;

    }

    void solve (int i , int [] candidates , int target , List <Integer> list , List<List<Integer>> ans){
        if(target==0){
            ans.add(new ArrayList<>(list));
            return;
        }
        if(i>=candidates.length || target<0)
            return;
        
        list.add(candidates[i]);
        solve(i+1, candidates, target-candidates[i], new ArrayList<>(list), ans);
        list.remove(list.size()-1);
        int number = candidates[i];
        while(i<candidates.length||candidates[i]==number)
        i++;
        solve(i+1, candidates, target, list, ans);
    }
}