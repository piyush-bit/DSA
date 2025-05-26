#include <bits/stdc++.h>
// #include<vector>
// #include<string>
// #include<iostream>
using namespace std;
using ll = long long;

bool check(const vector<ll>& y, int i, int j) {
    int n = y.size();
    ll dx = j - i;
    ll dy = y[j] - y[i];
    ll bA = y[i] * dx - dy * (i + 1);

    bool sawB = false;
    ll bB = 0;

    for (int t = 0; t < n; t++) {
        if (dy * (t - i) == dx * (y[t] - y[i])) {
            continue;
        }
        ll curB = y[t] * dx - dy * (t + 1);
        if (!sawB) {
            sawB = true;
            bB = curB;
            if (bB == bA) return false;
        } else {
            if (curB != bB) return false;
        }
    }
    return sawB;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> y(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    bool ok = false;
    if (check(y, 0, 1)) ok = true;
    else if (check(y, 0, 2)) ok = true;
    else if (check(y, 1, 2)) ok = true;

    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}
