#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
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
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    
    // Count dashes and underscores
    ll dashCount = 0;
    ll underscoreCount = 0;
    for (auto c : s) {
        if (c == '-')
            dashCount++;
        else if (c == '_')
            underscoreCount++;
    }
    
    // Calculate optimal distribution of dashes
    ll firstGroupDashes = dashCount / 2;
    ll lastGroupDashes = dashCount - firstGroupDashes;
    
    // Calculate number of "-_-" subsequences
    ll result = firstGroupDashes * underscoreCount * lastGroupDashes;
    
    cout << result << endl;
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