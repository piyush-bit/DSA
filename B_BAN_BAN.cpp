#include<vector>
#include<string>
#include<iostream>
// #include <bits/stdc++.h>
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
    string res;
    if(n==1){
        cout<<"1\n1 2\n";
        return ;
    }
    if(n==2){
        cout<<"1\n2 6\n";
        return ;
    }

    rep(i, 0, n) res += "BAN";
    int c=0;
    int i =0 , j= 3*n-1;
    vector<pair<int,int>>ans;
    while(i<j){
        if(res[i]=='N')i++;
        if(i>=j)break;
        swap(res[i], res[j]);
        ans.pb({i + 1, j + 1});
        c++;
        i++;
        j-=3;
    }
    cout<<c<<"\n";
    for(auto &i : ans){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}