#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
class Solution {
public:
std::vector<int> longestPalindromeLengthsFromEachIndex(const std::string& s) {
    int n = s.size();
    if (n == 0) return {};

    // Step 1: Transform the string with separators
    std::string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int m = t.size();
    std::vector<int> p(m, 0);
    int center = 0, right = 0;

    // Step 2: Manacher's algorithm
    for (int i = 0; i < m; ++i) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = std::min(right - i, p[mirror]);

        // Try to expand
        int a = i + p[i] + 1;
        int b = i - p[i] - 1;
        while (a < m && b >= 0 && t[a] == t[b]) {
            ++p[i];
            ++a;
            --b;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    // Step 3: Extract longest palindromes starting at each index
    std::vector<int> res(n, 1); // minimum palindrome length is 1

    for (int i = 0; i < m; ++i) {
        if (p[i] == 0) continue;
        int start = (i - p[i]) / 2;
        int end = (i + p[i]) / 2 - 1;
        if (start < n) {
            int len = end - start + 1;
            res[start] = std::max(res[start], len);
        }
    }

    return res;
}

    std::vector<int> longestPalindromeLengthsEndingAtEachIndex(const std::string& s) {
    int n = s.size();
    if (n == 0) return {};

    // Step 1: Transform the string with separators
    std::string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int m = t.size();
    std::vector<int> p(m, 0);
    int center = 0, right = 0;

    // Step 2: Manacher's algorithm
    for (int i = 0; i < m; ++i) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = std::min(right - i, p[mirror]);

        // Try to expand
        int a = i + p[i] + 1;
        int b = i - p[i] - 1;
        while (a < m && b >= 0 && t[a] == t[b]) {
            ++p[i];
            ++a;
            --b;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    // Step 3: Extract longest palindromes ending at each index
    std::vector<int> res(n, 1); // minimum palindrome length is 1

    for (int i = 0; i < m; ++i) {
        if (p[i] == 0) continue;
        int start = (i - p[i]) / 2;
        int end = (i + p[i]) / 2 - 1;
        if (end < n) {
            int len = end - start + 1;
            res[end] = std::max(res[end], len);
        }
    }

    return res;
}

    int longestPalindrome(string s, string t) {
        int n = s.size();
        int m = s.size();

        vector<int> p =  longestPalindromeLengthsFromEachIndex(s);
        vector<int> q = longestPalindromeLengthsEndingAtEachIndex(t);

        

        
    }
};