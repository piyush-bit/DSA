#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        queue<pair<int, int>> q;
        int operations = 0;

        for (int i = 0; i < n;) {
            if (nums[i] == 0) {
                i++;
                continue;
            }
            int start = i;
            while (i < n && nums[i] != 0) i++;
            q.push({start, i - 1});
        }

        while (!q.empty()) {
            auto [l, r] = q.front();
            q.pop();

            int mn = INT_MAX;
            for (int i = l; i <= r; ++i) {
                if (nums[i] != 0)
                    mn = min(mn, nums[i]);
            }

            for (int i = l; i <= r; ++i) {
                if (nums[i] == mn)
                    nums[i] = 0;
            }

            operations++;

            for (int i = l; i <= r;) {
                if (nums[i] == 0) {
                    i++;
                    continue;
                }
                int start = i;
                while (i <= r && nums[i] != 0) i++;
                q.push({start, i - 1});
            }
        }

        return operations;
    }
};
