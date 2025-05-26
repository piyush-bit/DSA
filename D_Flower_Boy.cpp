// Author: YourName
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // 1) Greedy without insertion
    vector<int> pref(n+1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i];
        if (pref[i] < m && a[i] >= b[pref[i]]) {
            pref[i+1] = pref[i] + 1;
        }
    }
    if (pref[n] == m) {
        cout << 0 << '\n';
        return;
    }

    // 2) Build suffix matches for b backwards
    vector<int> suff(n+1);
    suff[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        suff[i] = suff[i+1];
        if (suff[i+1] < m && a[i] >= b[m-1 - suff[i+1]]) {
            suff[i] = suff[i+1] + 1;
        }
    }

    // 3) Function to test if inserting k works
    auto can = [&](int k) {
        for (int i = 0; i <= n; i++) {
            int matched = pref[i];
            if (matched >= m) return true;
            // try inserting at position i to match b[matched]
            if (k < b[matched]) continue;
            // after insertion, need to match (m - matched - 1) from suffix starting at i
            int need = m - matched - 1;
            if (suff[i] >= need) return true;
        }
        return false;
    };

    // 4) Binary search for minimum k
    int low = 1, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
