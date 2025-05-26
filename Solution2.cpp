#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        string smallestPalindrome(string s, int k) {
            int n = s.size();
            string kth = getkth(s.substr(0, n/2), k);
            string rev_kth = kth;
            reverse(rev_kth.begin(), rev_kth.end());
            if(n%2==0){
                return kth + rev_kth;
            }else{
                return kth + s[n/2] + rev_kth;
            }
        
        }
        string getkth(string s , int k){
            vector<int> fr (26,0);
            int total = 0;
            for(auto i : s){
                total++;
                fr[i-'a']++;
            }
            for(int i =0 ; i<26 ; i++){
                fr[i]--;
                long long per = findPeru(fr , total);
                if(k-per <=0){
                    //go deep
                }
            }
        }

        long long findPeru(const vector<int>& fr,int total){
            long long per =0;
            for(int i :fr){
                int 
            }
        }
    };