#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp (amount + 1, INT_MAX);

        sort(begin(coins), end(coins));
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {

            for (int j = 0; j < coins.size(); ++j) {

                if (i >= coins[j]) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
                else {
                    // if coin is much larger than the curr amount
                    break;
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount] ;
    }
};

int main(void) {
    Solution sol;
    vector<int> den = {1, 5, 6, 8};
    int total = 11;
    cout << sol.coinChange(den, total) << "\n";
}

// Tc: O(amount * denominations), SC: O(amount)