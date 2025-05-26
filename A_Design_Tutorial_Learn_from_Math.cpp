#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 1;

vector<bool> is_prime(MAXN, true);
vector<bool> is_composite(MAXN, false);

// Precompute prime and composite status using sieve
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 4; i < MAXN; ++i)
        if (!is_prime[i])
            is_composite[i] = true;
}

int main() {
    int n;
    cin >> n;

    sieve();

    for (int i = 4; i < n; ++i) {
        if (is_composite[i] && is_composite[n - i]) {
            cout << i << " " << (n - i) << endl;
            break;
        }
    }

    return 0;
}
