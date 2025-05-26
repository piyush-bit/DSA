// Author: Piyush
#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
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
    int n , k;
    cin >> n >> k;
    int maxi =0;int mini=k+1;
    vector<int>a(n,0);
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    int sum =-1;
    bool diff = false;
    for(int i = 0 ; i<n ; i++){
        int temp;
        cin>>temp;
        if(temp==-1)
        continue;

        int lsum = temp+a[i];
        if(sum==-1){
            sum = lsum;
        }else{
            if(sum!=lsum)
            {
                diff=true;
            }
        }
    }

    if(diff){
        cout<<0<<"\n";
        return;
    }

    if(sum==-1){
        int maxs = mini+k;
        // cout<<"maxs->"<<maxs<<"mini->"<<mini<<"\n";
        cout<<maxs-maxi+1<<"\n";
        return;
    }

    if(sum>mini+k || sum <maxi){
        cout<<0<<"\n";
        return;
    }

    cout<<1<<"\n";
        return;




}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}