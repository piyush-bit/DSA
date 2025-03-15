#include <iostream>
#include<cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

void solve() {
    int size , rsum , p ;
    cin>> size;
    cin>> rsum;
    cin >> p;

    if(rsum==0){
        cout<<0<<endl;
        return;
    }

    if(rsum>0){
        if(p*size < rsum){
            cout<<-1<<endl;
            return;
        }

        cout<<ceil(double(rsum)/p)<<endl;

    }else{
        if(p*size*-1 > rsum){
            cout<<-1<<endl;
            return;
        }
        cout<<ceil(-1*double(rsum)/p)<<endl;
    }
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}