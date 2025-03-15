using namespace std;
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return solve(s);
    }

    int solve (string s) {

        // create a int array o of size 256
        int o[256] ;

        memset(o,-1,sizeof(o));

        int i = 0 , j = 0 ;

        int max = 0 ; 

        while (i < s.length() && j < s.length()) {
            if(o[s[j]] < i) {
                o[s[j]] = j;
                j++;
                max = max > j - i ? max : j - i;
            } else {
                i = o[s[j]] + 1;
                o[s[j]] = j;
                j++;
            }
        }
        
        return max;
    }
};