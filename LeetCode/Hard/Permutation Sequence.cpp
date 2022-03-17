#include <bits/stdc++.h>
using namespace std;

class Solution {
    // O(N)
    void nextPermutation(string& s) {
        int k = s.size() - 2;
        while (k >= 0 && s[k] >= s[k + 1]) --k;

        if (k < 0) {
            reverse(begin(s), end(s));
        }
        else {
            int i = 0;
            for (i = s.size() - 1; i > k; --i) {
                if (s[i] > s[k]) {
                    break;
                }
            }
            swap(s[i], s[k]);
            reverse(begin(s) + k + 1, end(s));
        }
    }
public:
    string getPermutation(int n, int k) {
        if (n == 0) return "";

        // O(N)
        string s = string(n, '0');
        for (int i = 0; i < n; ++i) s[i] = ((i + 1) + '0');

        for (int i = 0; i < k - 1; ++i) {
            nextPermutation(s);
        }
        return s;
    }
};
// O(N*K)