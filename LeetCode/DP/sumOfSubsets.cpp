#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumOfSubsets(vector<int>& arr, int sum) {
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1));
        for (int i = 1; i <= arr.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j < arr[i]) {

                    // take the value above
                    dp[i][j] = dp[i - 1][j];
                }
                else {

                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
                }
            }
        }
        return dp[arr.size()][sum];
    }
};

int main(void) {
    Solution sol;
    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 11;
    cout << sol.sumOfSubsets(arr, sum);
}