// Author: YourName
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
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

    int q;
    cin >> q;
    
    while(q-->0){
        string s;
        cin >> s;

        if(s[0]=='-' && s[1]=='>'){
            int x, y;
            cin >> x >> y;  // Read x and y coordinates

            // cout<<x<<" "<<y<<endl;
            
            // Calculate the position number from coordinates
            // For a grid of size n, position (x,y) maps to (x-1)*n + y
            int number = (x-1)*n + y;
            cout << number << endl;
        }

        if(s[0]=='<' && s[1]=='-'){
            int d;
            cin >> d;  // Read the position number
            
            // Calculate coordinates from position number
            // For position d in grid of size n
            int x = (d/n)+1; // Row number
            int y = (d-1)%n +1; // Column number
            
            cout << x << " " << y << endl;
        }
    }
}


int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}