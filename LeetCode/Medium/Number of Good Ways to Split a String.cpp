#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSplits(string s, int res = 0) {
        int left[26] = {}, right[26] = {}, d_l = 0, d_r = 0;

        for (char ch : s) {
            d_r += ++right[ch - 'a'] == 1;
        }

        for (int i = 0; i < s.size(); ++i) {
            d_l += ++left[s[i] - 'a'] == 1;
            d_r -= --right[s[i] - 'a'] == 0;

            res += d_l == d_r;
        }

        return res;
    }
};