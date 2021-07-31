#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j <= i + nums[i] && j < n; ++j) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        return dp[0];
    }
};

// TC: O(N^2), SC: O(N)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int jumps = 1, currEnd = nums[0], currFarthest = nums[0];
        for (int i = 1; i < n; ++i) {
            if (i > currEnd) {
                ++jumps;
                currEnd = currFarthest;

                if (currFarthest >= n - 1) {
                    break;
                }
            }
            currFarthest = max(currFarthest, i + nums[i]);
        }
        return jumps;
    }
};


// TC: O(N), SC: O(1)
