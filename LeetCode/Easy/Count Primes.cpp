#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 2; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (bool x : prime) cout << x << "\n";
        return count(begin(prime), end(prime), true);
    }
};


// Efficient Method:- Half Sieve Of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        int res = 0;
        vector<bool> prime(n / 2);
        for (int i = 3; i < n; i += 2) {
            if (!prime[i / 2]) {
                ++res;
                for (auto j = (long long)i * i; j < n; j += i) {
                    if (j % 2) {
                        prime[j / 2] = true;
                    }
                }
            }
        }
        return res + 1;
    }
};

