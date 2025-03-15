class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        solve(1, k, n, list, ans);
        return ans;
    }

    void solve(int i  ,int k , int n , List <Integer> list , List<List<Integer>> ans){
        if(k==0 && n==0){
            ans.add(new ArrayList<>(list));
            return;
        }
        if(k==0 || n==0)
            return;
        for(int p=i;p<=9;p++){
            list.add(p);
            solve(p+1, k-1, n-p, list, ans);
            list.remove(list.size()-1);
        }
    }
}