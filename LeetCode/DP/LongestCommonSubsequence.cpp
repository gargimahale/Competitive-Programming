#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        vector<vector<short>> dp(a.size() + 1, vector<short>(b.size() + 1));
        for (int i = 1; i <= a.size(); ++i) {
            for (int j = 1; j <= b.size(); ++j) {
                if (b[j - 1] == a[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[a.size()][b.size()];
    }
};

int main(void) {
    Solution sol;
    string a = "abcdaf", b = "acbcf";
    cout << sol.longestCommonSubsequence(a, b);
}