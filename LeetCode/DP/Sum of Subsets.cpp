#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumOfSubsets(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        // sum is 0
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j < arr[i - 1]) {
                    // take the value above
                    dp[i][j] = dp[i - 1][j];
                }
                else {

                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};

int main(void) {
    Solution sol;
    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 11;
    cout << sol.sumOfSubsets(arr, sum);
}