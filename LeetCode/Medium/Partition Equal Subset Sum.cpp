#include <bits/stdc++.h>
using namespace std;

// TC and SC: O(N*M)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int& a : nums) sum += a;

        if (sum % 2 != 0) return false;
        sum /= 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};

// TC: O(N*M), SC: O(Sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        
        if (sum % 2){
            return false;
        }
        
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        
        for (int num: nums){
            for (int i = sum; i >= 0; --i){
                if (i >= num){
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }
        return dp[sum];
    }
};