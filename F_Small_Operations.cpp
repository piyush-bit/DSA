// Author: YourName
// #include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<set>
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


map<int, int> getPrimeFactors(int x) {
    map<int, int> pf;
    for (int i = 2; i*i <= x; ++i) {
        while (x % i == 0) {
            pf[i]++;
            x /= i;
        }
    }
    if (x > 1) pf[x]++;
    return pf;
}

// Bin-packing style grouping of primes such that group product <= k
int groupPrimes(multiset<int> primes, int k) {
    vector<int> bins;
    for (auto it = primes.rbegin(); it != primes.rend(); ++it) {
        int p = *it;
        bool placed = false;
        for (auto& bin : bins) {
            if (bin * p <= k) {
                bin *= p;
                placed = true;
                break;
            }
        }
        if (!placed) bins.push_back(p);
    }
    return bins.size();
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    if (x == y) {
        cout << 0 << '\n';
        return;
    }

    map<int, int> fx = getPrimeFactors(x);
    map<int, int> fy = getPrimeFactors(y);

    // Check for impossible case: x has extra primes not in y
    for (auto [p, cnt] : fx) {
        if (fy[p] < cnt) {
            cout << -1 << '\n';
            return;
        }
    }

    // Build missing primes from x to y
    multiset<int> needed;
    for (auto [p, cy] : fy) {
        int cx = fx[p];
        for (int i = 0; i < cy - cx; ++i) {
            needed.insert(p);
        }
    }

    // Exponentiation trick (x^a): try to use one exponentiation if useful
    int min_ops = groupPrimes(needed, k); // default: all multiplications

    for (int a = 2; a <= k; ++a) {
        map<int, int> fx_pow;
        bool valid = true;
        for (auto [p, cnt] : fx) {
            fx_pow[p] = cnt * a;
            if (fx_pow[p] > fy[p]) valid = false;
        }
        if (!valid) continue;

        // Now find the leftover primes needed
        multiset<int> left;
        for (auto [p, cnt] : fy) {
            int used = fx_pow[p];
            for (int i = 0; i < cnt - used; ++i) {
                left.insert(p);
            }
        }

        int current_ops = 1 + groupPrimes(left, k); // one exponent op + multiplications
        min_ops = min(min_ops, current_ops);
    }

    cout << min_ops << '\n';
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
