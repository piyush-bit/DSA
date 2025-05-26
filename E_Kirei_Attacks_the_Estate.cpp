// Author: YourName
#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define ll long long
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

int n;
vector<vector<int>> adj;
vector<ll> a, threat;
void dfs(int v, int parent, int depth, ll sum, ll minSum, ll maxSum) {
    if ((depth & 1) == 0)
        threat[v] = sum - minSum;
    else
        threat[v] = maxSum - sum;

    minSum = min(minSum, sum);
    maxSum = max(maxSum, sum);

    for (int u : adj[v]) if (u != parent) {
        ll nextSum = sum + (((depth+1)&1) ? -a[u] : +a[u]);
        dfs(u, v, depth+1, nextSum, minSum, maxSum);
    }
}

void solve() {
    cin >> n;
    a.assign(n+1, 0);
    adj.assign(n+1, {});
    threat.assign(n+1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0, a[1], 0LL, 0LL);

    for (int i = 1; i <= n; i++)
        cout << threat[i] << (i==n? '\n' : ' ');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
