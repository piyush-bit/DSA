// Author: YourName
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>

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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    vi bc(60, 0);
    rep(i, 0, n) {
        rep(j, 0, 60) {
            if(a[i] & (1LL << j)) bc[j]++;
        }
    }
    
    int mx = 0, idx = 0;
    rep(k, 0, n) {
        int cur = 0;
        rep(j, 0, 60) {
            int ones = bc[j];
            if(a[k] & (1LL << j)) {
                cur += (n - ones) * (1LL << j);
            } else {
                cur += ones * (1LL << j);
            }
        }
        if (cur > mx) {
            mx = cur;
            idx = k;
        }
    }
    
    cout << mx << "\n";
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}