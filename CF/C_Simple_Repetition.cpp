// Author: YourName
#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

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

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve() {
    int x, k;
    cin >> x >> k;
    int ans = 0;
    while (k-- > 0) {
        ans = ans * (long long)pow(10, k) + x;
    }

    if (isPrime(ans)) {
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