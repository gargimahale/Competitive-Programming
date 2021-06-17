#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        if (n == 0) {
            return {};
        }
        vector<int> charLoc;
        vector<int> ans(n);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                charLoc.emplace_back(i);
            }
        }

        int m = charLoc.size();
        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (i > charLoc[right]) {
                left = right;
                if (right < m - 1) {
                    ++right;
                }
            }
            ans[i] = min(abs(charLoc[right] - i), abs(charLoc[left] - i));
        }
        return ans;
    }
};