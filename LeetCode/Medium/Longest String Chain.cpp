#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        if (len <= 1) return len;

        sort(begin(words), end(words), [&](auto a, auto b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int res = 0;

        for (string word : words) {
            int l = word.size();
            for (int i = 0; i < l; ++i) {
                string pre = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[word]);
        }

        return res;
    }
};


// TC: O(N* S^2)
// SC: O(N)