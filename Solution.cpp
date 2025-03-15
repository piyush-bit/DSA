#include <vector>
using namespace std;
class Solution {
public:

    bool solve (int i , int target , vector<int>& nums , vector<vector<int>> dp){
        if(target==0){
            return true ;
        }

        if(i >= nums.size()){
            return false;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        bool take = solve(i+1 , target-nums[i],nums,dp);
        bool notTake = solve(i+1,target, nums,dp);

       dp[i][target]= take || notTake ? 1:0; ;
       return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for ( int e : nums ) sum += e;
        if(sum%2!=0){
            return false ; 
        }
        
        vector<vector<int>> dp (nums.size(),vector<int>(sum/2,0));

        for(int i =0 ; i < nums.size() ; i++){
            dp[i][0]=1;
        }

        
        
    }
};