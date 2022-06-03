#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if (n < 2 || k == 0) return 0;

        vector<vector<int>> dp(k + 1, vector<int> (n));

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                int maxVal = 0;
                for (int m = 0; m < j; ++m) {
                    maxVal = max(maxVal, prices[j] - prices[m] + dp[i - 1][m]);
                }
                dp[i][j] = max(maxVal, dp[i][j - 1]);
            }
        }
        return dp[k][n - 1];
    }
};
// TC: O(days^2 * k), SC: O(days * k)


// OR
// TC and SC: O(Days * k)
class Solution_1 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if (n < 2 || k == 0) return 0;

        vector<vector<int>> dp(k + 1, vector<int> (n));

        for (int i = 1; i < dp.size(); ++i) {
            int maxDiff = -prices[0];
            for (int j = 1; j < dp[0].size(); ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][n - 1];
    }
};