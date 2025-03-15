import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        solve(n,n,"",list);
        return list;
        
    }

    void solve(int o , int c , String ans , List<String> list){
       if(o==0 && c==0){
           list.add(ans);
           return;
       }
       if(o==0){

           solve(o, c-1, ans+")", list);
           return ; 
       }

       if(o<c){
           solve(o-1, c, ans+"(", list);
           solve(o, c-1, ans+")", list);
       }
       else
           solve(o-1, c, ans+"(", list);
    }
}