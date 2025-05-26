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

unordered_map<int64_t, bool> dp; 
int64_t encode(int pc, int sc) {
    return (int64_t)pc << 32 | sc; 
}

bool f(const string &p, const string &s, int pc, int sc) {
    if (pc == p.size() || sc == s.size()) {
        return pc == p.size() && sc == s.size();
    }

    int64_t key = encode(pc, sc);
    if (dp.count(key)) return dp[key];

    char h = p[pc];
    bool ans = false;

    if (h == 'L') {
        if (s[sc] == 'L') {
            ans |= f(p, s, pc + 1, sc + 1);
            if (!ans && sc + 1 < s.size() && s[sc + 1] == 'L') {
                ans |= f(p, s, pc + 1, sc + 2);
            }
        }
    } else { // h == 'R'
        if (s[sc] == 'R') {
            ans |= f(p, s, pc + 1, sc + 1);
            if (!ans && sc + 1 < s.size() && s[sc + 1] == 'R') {
                ans |= f(p, s, pc + 1, sc + 2);
            }
        }
    }

    return dp[key] = ans;
}

void solve() {
    string p, s;
    cin >> p >> s;
    dp.clear(); 
    cout << (f(p, s, 0, 0) ? "YES\n" : "NO\n");
}


int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}