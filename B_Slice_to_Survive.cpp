// Author: Piyush
#include <bits/stdc++.h>
// #include <iostream>
// #include<vector>
// #include<map>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define int long long
#define pb push_back
#define aint(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define per(i,a,b) for (int i = a; i >= b; --i)
using pii = pair<int,int>;
using vi = vector<int>;

const int INF = 1e18;
const int MOD = 1e9+7;
const int N = 2e5+5;


int min_turns(int x) {
    int cnt = 0;
    while (x > 1) {
        x = (x + 1) / 2;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    int rr = min(a, n - a + 1);
    int cc = min(b, m - b + 1);

    int orw = 1 + min_turns(rr) + min_turns(m);
    int ocl = 1 + min_turns(n) + min_turns(cc);

    int tt = min(orw, ocl);
    cout << tt << "\n";
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
