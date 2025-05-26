#include <bits/stdc++.h>

// #include <iostream>
// #include <string>
// #include <vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<ll,ll>> mons(n);
        for (auto &p : mons) {
            cin >> p.first >> p.second;
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        vector<ll> xs(n), ys(n);
        for (int i = 0; i < n; i++) {
            xs[i] = mons[i].first;
            ys[i] = mons[i].second;
        }
        auto find_two = [&](const vector<ll> &v){
            ll mn = LLONG_MAX, mn2 = LLONG_MAX;
            ll mx = LLONG_MIN, mx2 = LLONG_MIN;
            for (ll x : v) {
                if (x < mn) {
                    mn2 = mn; mn = x;
                } else if (x < mn2) {
                    mn2 = x;
                }
                if (x > mx) {
                    mx2 = mx; mx = x;
                } else if (x > mx2) {
                    mx2 = x;
                }
            }
            return array<ll,4>{mn, mn2, mx, mx2};
        };

        auto ax = find_two(xs);
        auto ay = find_two(ys);
        ll baseW = ax[2] - ax[0] + 1;
        ll baseH = ay[2] - ay[0] + 1;
        ll answer = baseW * baseH;

        for (int i = 0; i < n; i++) {
            ll x = mons[i].first, y = mons[i].second;

            ll xmin = ax[0], xmax = ax[2];
            if (x == ax[0]) xmin = ax[1];
            if (x == ax[2]) xmax = ax[3];

            ll ymin = ay[0], ymax = ay[2];
            if (y == ay[0]) ymin = ay[1];
            if (y == ay[2]) ymax = ay[3];

            ll W = xmax - xmin + 1;
            ll H = ymax - ymin + 1;
            ll A = W * H;

            if (A == n - 1) {
                A = min((W+1)*H, W*(H+1));
            }
            answer = min(answer, A);
        }

        cout << answer << "\n";
    }

    return 0;
}
