// Author: YourName
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        vector<long long> p(n+1, 0);
        vector<bool> u(n+1, false);

        
        for (long long i = 1; i <= n; ++i) {
            if (p[i] != 0) continue;
            if ((i & ~x) != 0) continue;
            long long j = x ^ i;
            if (j < 1 || j > n) continue;
            if (p[j] != 0) continue;
            p[i] = j;
            p[j] = i;
            u[i] = u[j] = true;
        }

        
        vector<long long> r;
        for (long long v = 1; v <= n; ++v) {
            if (!u[v]) r.push_back(v);
        }
        int idx = 0;
        for (long long i = 1; i <= n; ++i) {
            if (p[i] == 0) {
                p[i] = r[idx++];
            }
        }

       
        for (long long i = 1; i <= n; ++i) {
            cout << p[i] << (i==n ? '\n' : ' ');
        }
    }
    return 0;
}
