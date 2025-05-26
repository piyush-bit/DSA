// Author: YourName
#include <bits/stdc++.h>
// #include <iostream>
// #include<vector>
// #include<map>

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
struct Node {
    int dif;
    int pos;
    bool isvalid;
};
void solve() {
    int n;
    cin >> n;

    unordered_map<int, Node> m;
    m.reserve(n);

    for (int idx = 0; idx < n; idx++) {
        int t;
        cin >> t;

        auto it = m.find(t);
        if (it != m.end()) {
            Node &node = it->second;
            int oldPos = node.pos;

            if (node.dif == -1) {
                node.dif = idx - oldPos;
                node.pos = idx;
            }
            else if (node.isvalid) {
                if (node.dif == idx - oldPos) {
                    node.pos = idx;
                } else {
                    node.isvalid = false;
                }
            }
        }
        else {
            m[t] = Node{ -1, idx, true };
        }
    }
    vector<pair<int,int>> valid;
        valid.reserve(m.size());
        for (auto &kv : m) {
            if (kv.second.isvalid) {
                valid.emplace_back(kv.first, kv.second.dif);
            }
        }
        sort(valid.begin(), valid.end(),
            [](auto &A, auto &B) {
                if (A.first != B.first)
                    return A.first < B.first;
                return A.second < B.second;
            });

        cout << valid.size() << "\n";
        for (auto &pr : valid) {
            cout << pr.first << " " << (pr.second == -1 ? 0 : pr.second) << "\n";
        }
}


int32_t main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}