#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

const int MAX = 1e6 + 1;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    // Sieve of Eratosthenes up to 10^6
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }

    // Store squares of primes
    unordered_set<long long> t_primes;
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            t_primes.insert(1LL * i * i);
        }
    }

    // Answer queries
    for (long long x : nums) {
        if (t_primes.count(x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
