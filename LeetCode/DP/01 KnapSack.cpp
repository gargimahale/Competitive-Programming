#include <bits/stdc++.h>
using namespace std;

// 0-1 KnapSack
// TC: O(n*cap)
// SC: O(n*cap)

class Solution {
public:
    int solveKnapSack(vector<int>& wt, vector<int>& val, int n, int cap) {
        vector<vector<int>> dp(n + 1, vector<int>(cap + 1));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= cap; ++j) {

                // when the cap is less than the cap of the item
                if (j < wt[i]) {
                    // Take the max Value found so far by not considering the current item
                    dp[i][j] = dp[i - 1][j];
                }

                else {
                    // max((item taken + item that can be taken with remaining weight), the max you can do without taking the item)
                    dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
                }
            }
        }
        return dp[n][cap];
    }
};

int main(void) {
    Solution sol;
    int cap = 7;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int n = wt.size();
    cout << sol.solveKnapSack(wt, val, n, cap);
}