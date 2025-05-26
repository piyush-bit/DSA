#include<string>
#include<vector>
using namespace std ;
using ll = long long;

class Solution {
    public:
        string smallestPalindrome(string s,int k) {
            vector<int> m (26,0);
            int n = s.size();

            for(int i =0 ; i<n/2 ; i++){
                m[s[i]-'a']++;
            }
            if(n%2==0){
                
                string pr ;
                try
                {
                    pr=kthPermutation(m,k);
                }
                catch(const exception& e)
                {
                    return "";
                }
                
                string rev = pr;
                reverse(rev.begin(), rev.end());
                return pr + rev;
            }else{
                string pr ;
                try
                {
                    pr=kthPermutation(m,k);
                }
                catch(const exception& e)
                {
                    return "";
                }
                string rev = pr;
                reverse(rev.begin(), rev.end());
                return pr+s[n/2]+rev;
            }
        }
        

        ll factorial(int n) {
            static vector<ll> fact(21, 0);
            if (fact[0] == 0) {
                fact[0] = 1;
                for (int i = 1; i <= 20; ++i)
                    fact[i] = fact[i - 1] * i;
            }
            return fact[n];
        }

        // Compute multinomial coefficient: total! / (m[0]! * m[1]! * ... * m[25]!)
        ll countPerms(const vector<int>& m) {
            int total = 0;
            for (int x : m) total += x;
            ll denom = 1;
            for (int x : m) denom *= factorial(x);
            return factorial(total) / denom;
        }

        string kthPermutation(vector<int> m, ll k) {
            ll totalPerms = countPerms(m);
            if (k > totalPerms) {
                throw invalid_argument("k is greater than the total number of permutations.");
            }

            string result;
            int total_chars = 0;
            for (int x : m) total_chars += x;

            for (int pos = 0; pos < total_chars; ++pos) {
                bool found = false;
                for (int i = 0; i < 26; ++i) {
                    if (m[i] == 0) continue;

                    m[i]--;
                    ll perms = countPerms(m);

                    if (k <= perms) {
                        result += ('a' + i);
                        found = true;
                        break;
                    } else {
                        k -= perms;
                        m[i]++;
                    }
                }
                throw invalid_argument("k is greater than the total number of permutations.");
            }

            return result;
        }
    };

    