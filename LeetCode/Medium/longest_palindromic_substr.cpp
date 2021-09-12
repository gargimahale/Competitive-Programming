#include <bits/stdc++.h>
using namespace std;

// Expanding from the center
// TC: O(n^2), SC:O(1)

class Solution {
public:
    string getLongestPalindrome(string& s, bool type) {
        int st = 0, max_len = 1, l, r;
        for (int i = 0; i < s.size(); ++i) {
            if (type) {
                l = i, r = i + 1;
            }
            else {
                l = r = i;
            }
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                --l, ++r;
            }
            int len = r - l - 1;
            if (len > max_len) {
                max_len = len;
                st = l + 1;
            }
        }
        return s.substr(st, max_len);
    }

    string longestPalindrome(string& s) {
        if (s.size() < 2) return s;

        string odd = getLongestPalindrome(s, false);
        string even = getLongestPalindrome(s, true);
        return odd.size() > even.size() ? odd : even;
    }
};

int main(void) {
    Solution sol;
    string a = "babad";
    cout << sol.longestPalindrome(a) << "\n";
}