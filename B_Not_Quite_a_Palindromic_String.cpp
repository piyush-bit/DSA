// Author: YourName
#include <bits/stdc++.h>

// #include <iostream>
// #include <string>
// #include <vector>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define per(i,a,b) for (int i = a; i >= b; --i)
using pii = pair<int,int>;
using vi = vector<int>;

const int INF = 1e18;
const int MOD = 1e9+7;
const int N = 2e5+5;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int binpow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int z = 0, o = 0;
    for (char c : s) {
        if (c == '0') z++;
        else o++;
    }

    int bp = n / 2 - k;

    if (z < bp || o < bp) {
        cout << "NO\n";
        return;
    }

    z -= bp;
    o -= bp;

    if (z % 2 == 0 && o % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}