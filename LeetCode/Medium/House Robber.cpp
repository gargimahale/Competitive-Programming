#include <bits/stdc++.h>

using namespace std;


// recursive --> (Top-Down)
class Solution {
    int rob(vector<int>& nums, int i){
        if (i < 0) return 0;
        return max(rob(nums, i-2)+nums[i], rob(nums, i-1));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return rob(nums, n-1);
    }
};

// Recursive + memo (top-down)
class Solution_1 {
    int rob(vector<int>& nums, int i){
        if (i < 0) return 0;
        
        if (dp[i] >= 0){
            return dp[i];
        }
        
        return dp[i] = max(rob(nums, i-2)+nums[i], rob(nums, i-1));
    }
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n, -1);
        return rob(nums, n-1);
    }
};

// Iterative + memo (bottom-up)
class Solution_2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 1){
            return 0;
        }
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i = 1; i<n; ++i){
            int val = nums[i];
            dp[i+1] = max(dp[i], dp[i-1]+val); 
        }
        return dp[n];
    }
};

// Iterative + 2 variables (bottom-up)
class Solution_3 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1){
            return 0;
        }
        
        int prev = 0, curr = 0;
        for (int i = 0; i<n; ++i){
            int temp = max(prev+nums[i], curr);
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
};