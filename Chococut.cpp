#include<vector>
#include<string>
#include<iostream>
// #include <bits/stdc++.h>
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
    long long N, M, K;
    cin >> N >> M >> K;

    long long total = N * M;
    long long best = 0;

    if (K <= total) {
        long long r = (K + M - 1) / M;
        long long give = r * M;
        best = max(best, total - give);
    }

    if (K <= total) {
        long long c = (K + N - 1) / N;
        long long give = c * N;
        best = max(best, total - give);
    }

    cout << best << "\n";
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}