class Solution {
    char [][] keymap={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    public List<String> letterCombinations(String digits) {

        List<String> list = new ArrayList<>();
        if(digits.length()==0)
            return list;
        StringBuilder ans = new StringBuilder();
        solve(0, digits, ans, list);
        return list;
    }

    void solve(int i , String digits , StringBuilder ans , List<String> list){
        if(i==digits.length()){
            list.add(ans.toString());
            return; 
        }

        for(int i=0 ; i<4 ;i++){
            if(i==4 && (digits.charAt(i)=='7' || digits.charAt(i)=='9'))
                continue;

            ans.append(keymap[digits.charAt(i)-'0'][i]); 
            solve(i+1, digits, ans, list);
            ans.deleteCharAt(ans.length()-1);
        }
    }
}