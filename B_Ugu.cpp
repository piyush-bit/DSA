// Author: YourName
// #include<vector>
// #include<string>
// #include<iostream>
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


void solve() {
    int n;
    cin >> n;
    string a ;
    cin >> a;

    int start = a[0];
    int last=start;
    int c=start-'0';
    rep(i,1,n){
        if(last!=a[i]){
            last=a[i];
            c++;
        }
    }
    if(c!=0)
        cout<<c-1<<"\n";
    else
        cout<<c<<"\n";
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}