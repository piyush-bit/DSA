#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;

        unordered_map<int,int> freqTop, freqBot, freqLeft, freqRight;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                total += v;
                freqBot[v]++;
                freqRight[v]++;
            }
        }

        long long sumTop = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int v : grid[i]) {
                sumTop += v;
                freqTop[v]++;
                freqBot[v]--;
            }

            long long sumBot = total - sumTop;
            if (sumTop == sumBot) {
                return true;
            }

            long long diff = llabs(sumTop - sumBot);
            if (sumTop > sumBot) {
                if (canRemove(diff, 0, i, 0, n-1, grid, freqTop))
                    return true;
            } else {
                if (canRemove(diff, i+1, m-1, 0, n-1, grid, freqBot))
                    return true;
            }
        }

        long long sumLeft = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                int v = grid[i][j];
                sumLeft += v;
                freqLeft[v]++;
                freqRight[v]--;
            }

            long long sumRight = total - sumLeft;
            if (sumLeft == sumRight) {
                return true;
            }

            long long diff = llabs(sumLeft - sumRight);
            if (sumLeft > sumRight) {
                if (canRemove(diff, 0, m-1, 0, j, grid, freqLeft))
                    return true;
            } else {
                if (canRemove(diff, 0, m-1, j+1, n-1, grid, freqRight))
                    return true;
            }
        }

        return false;
    }

private:
    bool canRemove(int diff,
                   int r1, int r2,
                   int c1, int c2,
                   const vector<vector<int>>& grid,
                   const unordered_map<int,int>& freqMap) 
    {
        auto it = freqMap.find(diff);
        if (it == freqMap.end() || it->second == 0)
            return false;

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;
        int M = grid.size();
        int N = grid[0].size();

        if (rows > 1 && cols > 1)
            return true;

        if (rows == 1) {
            bool isFullWidth = (c1 == 0 && c2 == N-1);
            bool isTopOrBottom = (r1 == 0) || (r1 == M-1);
            if (!isFullWidth || !isTopOrBottom)
                return false;
            return (grid[r1][c1] == diff) || (grid[r1][c2] == diff);
        }

        if (cols == 1) {
            bool isFullHeight = (r1 == 0 && r2 == M-1);
            bool isLeftOrRight = (c1 == 0) || (c1 == N-1);
            if (!isFullHeight || !isLeftOrRight)
                return false;
            return (grid[r1][c1] == diff) || (grid[r2][c1] == diff);
        }

        return false;
    }
};
