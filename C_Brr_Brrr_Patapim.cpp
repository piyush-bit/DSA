// Author: YourName
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n));
    map<int, int> diag; 

    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> G[i][j];
            int s = i + j +2; 
            if (diag.count(s)){
                if(diag[s]!=G[i][j])
                    cout<<"panic\n";
                continue;
            };
            diag[s] = G[i][j];
        }
    }

    vector<int> p(2 * n + 1);
    vector<bool> used(2 * n + 1, false);

    for (auto [k, val] : diag) {
        p[k] = val;
        used[val] = true;
    }

    rep(i, 1, 2 * n + 1) {
        if (!used[i]) {
            p[1] = i;
            break;
        }
    }

    rep(i, 1, 2 * n + 1) cout << p[i] << " ";
    cout << "\n";
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}