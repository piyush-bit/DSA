#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<vector<long long>> memo;
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            
        }
        long long solve(string number , int limit , string s , bool bounded, int idx){
            if(memo[idx][bounded]!=0){
                return memo[idx][bounded];
            }
            if(number.size()-idx<=s.size()){
                if(bounded){
                    if(number.size()-idx<s.size()){
                        return 0;
                    }
                    if(number.substr(idx)>s){
                        return 1;
                    }else{
                        return 0;
                    }
                }
                return 1;
            }
            long long posibilities =0 ;
            if(bounded){
                int start = number[idx]-'0';
                if(start<=limit){
                    posibilities+= solve(number,limit,s,true,idx+1);
                }
                if(start==limit){
                    posibilities+= (limit-1)*solve(number,limit,s,false,idx+1);
                }else{
                    posibilities+=min(start-1,limit)*solve(number,limit,s,false,idx+1);
                }
            }else{
                posibilities= limit*solve(number,limit,s,false,idx+1);
                
            }
            memo[idx][bounded]=posibilities;
            return memo[idx][bounded];
        }
    };


    int main() {
        Solution solution;
        string number = "8800";
        string s = "52";
        int limit = 9; // Assuming the limit is 9 as it's not specified
        solution.memo = vector<vector<long long>>(number.size() + 1, vector<long long>(2, 0));
        long long result = solution.solve(number, limit, s, true, 0);
        cout << "Result: " << result << endl;

        cout << "Memoization Table:" << endl;
        for (size_t i = 0; i < solution.memo.size(); ++i) {
            for (size_t j = 0; j < solution.memo[i].size(); ++j) {
                cout << solution.memo[i][j] << " ";
            }
            cout << endl;
        }

        return 0;
    }