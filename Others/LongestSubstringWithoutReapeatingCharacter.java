import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        return solve(s);
    }

    int  solve(String s){
        HashMap<Character,Boolean> hs = new HashMap<>();
        int i = 0 ; 
        int j=0;
        int max = 0;
        while(j<s.length()&&i<s.length()){
            while(j<s.length()||!hs.containsKey(s.charAt(j))){
                hs.put(s.charAt(j),true);
                j++;
                if(j-i>max)
                max = j-i;
            }
            while(i<j&&s.charAt(i-1)!=s.charAt(j)){
                hs.remove(s.charAt(i));
                i++;
            }
        }
        return max;
    }
}