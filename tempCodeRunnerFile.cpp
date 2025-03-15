#include <vector>
using namespace std;


class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            vector<int> ps (n);
            int sum =0;
            for(int i : nums){
                sum+=i;
                ps.push_back(sum)
            }
        }
    };