#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to generate all primes up to limit using Sieve of Eratosthenes
vector<long long> sieveOfEratosthenes(long long limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<long long> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for (long long i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            
            // Mark all multiples of i as non-prime
            for (long long j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return primes;
}

// Function to solve N = p²q using the sieve directly
pair<long long, long long> findPQ(long long n, const vector<long long>& primes, vector<bool>& isPrime, long long sieveLimit) {
    // Try each prime as a potential p
    for (long long p : primes) {
        long long p_squared = p * p;
        
        // If p² > n, we can stop
        if (p_squared > n) {
            break;
        }
        
        // Check if p² divides n evenly
        if (n % p_squared == 0) {
            // Calculate potential q
            long long q = n / p_squared;
            
            // Check if q is prime
            if (q > 1) {
                // If q is within our sieve range, use the isPrime array directly
                if (q <= sieveLimit) {
                    if (isPrime[q]) {
                        return {p, q};
                    }
                } else {
                    // If q is larger than our sieve limit, we need to check primality differently
                    bool qIsPrime = true;
                    for (long long prime : primes) {
                        if (prime * prime > q) {
                            break;  // q is prime if no smaller prime divides it
                        }
                        if (q % prime == 0) {
                            qIsPrime = false;
                            break;
                        }
                    }
                    if (qIsPrime) {
                        return {p, q};
                    }
                }
            }
        }
    }
    
    return {-1, -1}; // If no solution found
}

int main() {
    // Read the number of test cases
    int t;
    cin >> t;
    
    // Read all test cases first to find the maximum value
    vector<long long> testCases(t);
    long long maxTestCase = 0;
    
    for (int i = 0; i < t; i++) {
        cin >> testCases[i];
        maxTestCase = max(maxTestCase, testCases[i]);
    }
    
    // Calculate the sieve limit based on the maximum test case
    // We need primes up to approximately sqrt(maxTestCase) for factors
    // But also need to check if q is prime up to maxTestCase/4 (when p=2)
    long long factorLimit = ceil(sqrt(maxTestCase));
    long long qLimit = maxTestCase / 4;  // This is the maximum possible q when p=2
    long long sieveLimit = max(factorLimit, min(qLimit, (long long)1e8));  // Cap at 10^8 for memory concerns
    
    // Generate primes up to the sieve limit
    vector<bool> isPrime(sieveLimit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (long long i = 2; i * i <= sieveLimit; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= sieveLimit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Generate the list of primes
    vector<long long> primes;
    for (long long i = 2; i <= sieveLimit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    // Process each test case
    for (int i = 0; i < t; i++) {
        long long n = testCases[i];
        
        auto [p, q] = findPQ(n, primes, isPrime, sieveLimit);
        
        if (p != -1 && q != -1) {
            cout << p << " " << q << endl;
        } else {
            cout << "N is not in the form p²q" << endl;
        }
    }
    
    return 0;
}