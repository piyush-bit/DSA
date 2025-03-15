#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector< int >  prev(text2.length()+1,0);
    //     vector< int >  cur(text2.length()+1,0);
    //     for(int i = text1.length()-1 ; i>=0 ; i--){
    //         cur[text2.length()] = 0; 
    //         for(int j = text2.length()-1; j>=0;j--){
    //             if(text1[i] == text2[j]){
    //                 cur[j]=1+prev[j+1];
    //             }else{
    //                 cur[j] =  max(prev[j],cur[j+1]);
    //             }
    //         }
    //         prev = cur;

    //     }
    //     return cur[0];
    // }

    string longestCommonSubsequence(string text1, string text2) {
        vector< string >  prev(text2.length()+1,"");
        vector< string >  cur(text2.length()+1,"");
        for(int i = text1.length()-1 ; i>=0 ; i--){
            cur[text2.length()] = ""; 
            for(int j = text2.length()-1; j>=0;j--){
                if(text1[i] == text2[j]){
                    cur[j]=text1[i]+prev[j+1];
                }else{
                    cur[j] = (prev[j].length() > cur[j+1].length()) ? prev[j] : cur[j+1];
                }
            }
            prev = cur;

        }
        return cur[0];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = longestCommonSubsequence(str1,str2); 
        string ans = "";
        int j =0;
        int k=0;
        for(int i =0 ; i<lcs.length() ; i++){
            
            while(str1[j] != lcs[i]){
                ans += str1[];
                j++;
            }
            while(str2[k] != lcs[i]){
                ans += str2[i];
                k++;
            }
            ans += lcs[i];
            i++;
        }
        while(j<str1.length()){
            ans += str1[j];
            j++;
        }
        while(k<str2.length()){
            ans += str2[k];
            k++;
        }
        return ans;
    }




    int search (string text1 , string text2 , int i , int j ,vector < vector<int> > dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i == text1.length() || j == text2.length()){
            return 0;
        }
        if(text1[i] == text2[j]){
            dp[i][j] = 1 + search(text1,text2,i+1,j+1,dp);
        }else{
            dp[i][j] =  max(search(text1,text2,i+1,j,dp),search(text1,text2,i,j+1,dp));
        }

        return dp[i][j];
    }

    // int longestPalindromeSubseq(string s) {
    //     string rev = s;
    //     reverse(rev.begin(),rev.end());
    //     return longestCommonSubsequence(s,rev);
        
    // }
};

int main (){
    Solution s ; 
    cout<< s.longestCommonSubsequence("abcbdab","bdcaba");
    
}