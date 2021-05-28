#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        int n = s.size();
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                for (string w : wordDict) {
                    if (s.substr(i, w.size()).compare(w) == 0) {
                        dp[i + w.length()] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};


int main(void) {
    Solution sol;
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << sol.wordBreak(s, wordDict);
}

// TC: O(n^3)
// SC: O(n)