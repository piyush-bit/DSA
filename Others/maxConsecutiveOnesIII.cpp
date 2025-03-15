using namespace std ;
#include <iostream>
#include <vector>
#include <queue>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        queue < int > q;

        int i = 0 , j = 0 , max = -1 ;
        while (j < nums.size()) {

            if (nums[j] == 0) {
                if(q.size() > k) {
                    max = max > j - i-1 ? max : j - i-1;
                    int vx = j+1;
                    if(!q.empty()){
                         vx = q.front();
                             q.pop();
                    }
                    i = vx + 1;
                }
                q.push(j);
            }
            j++;
        }

        return max!=-1?max:nums.size() ;

    }

    // run from main function 
    int main()
    {
        cout << "[1,1,1,0,0,0,1,1,1,1,0] "<< Solution().longestOnes({1,1,1,0,0,0,1,1,1,1,0},2)<< endl;
    }
    

};