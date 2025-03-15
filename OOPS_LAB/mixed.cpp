#include<vector>
using namespace std ; 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<pair<int,int>> dp (nums.size(),pair<int,int>(1,-1));
        pair M={1,0};
        for(int i  = 1 ; i<nums.size() ; i++){
            int max = 0;
            for(int j = i-1 ; j>=0 ; j++){
                if(dp[j].first > max){
                    if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0){
                        max=dp[j].first;
                        dp[i]={1+dp[j].first,j};
                        if(1+dp[j].first>M.first){
                            M = {1+dp[j].first,i};
                        }
                    }
                }
            }
        }
        vector<int> ans ;
        while(true){
            ans.push_back(nums[M.second]);
            if(M.second!=-1)
            M=dp[M.second];
            else
            break;
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};