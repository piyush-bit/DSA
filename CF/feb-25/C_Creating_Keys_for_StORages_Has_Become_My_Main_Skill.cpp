#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include<unordered_set>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    
    vi ans;
    unordered_set<int> us;
    
    // Add numbers that satisfy (k | x) == x and don't exceed x
    for (int k = 0; k <= x; k++) {
        if ((k | x) == x) {
            ans.push_back(k);
            us.insert(k);
            if (ans.size() == n) break;
        }
    }
    
    // If we haven't filled the array yet, repeat the largest number
    int largest = ans.empty() ? 0 : ans.back();
    while (ans.size() < n) {
        ans.push_back(largest);
    }
    
    // Check if x is already included in the array
    bool has_x = (us.find(x) != us.end());
    
    // If x is not in array and needed to satisfy the OR condition, replace the last element
    if (!has_x) {
        int bitwise_or = 0;
        for (int num : ans) {
            bitwise_or |= num;
        }
        
        if (bitwise_or != x) {
            ans[n-1] = x;
        }
    }
    
    // Print the array
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}