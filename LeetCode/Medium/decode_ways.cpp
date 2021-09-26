#include <bits/stdc++.h>
using namespace std;

// Top down DP - Time: O(N), Space: O(N)
/*
    For a character s[i], we have 2 ways to decode:
    Single digit: Require s[i] != '0' (decoded to 1..9)
    Two digits: Require i + 1 < len(s) and (s[i] == 1 (decoded to 10..19) 
        or s[i] == 2 and s[i+1] <= '6') (decoded to 20..26).
 */ 
class Solution { // 12 ms, faster than 9.19%
public:
    int memo[100] = {};
    int numDecodings(const string& s) {
        return dp(s, 0);
    }
    int dp(const string& s, int i) {
        if (i == s.size()) return 1;
        if (memo[i] != 0) return memo[i];
        int ans = 0;
        if (s[i] != '0') // Single digit
            ans += dp(s, i+1);
        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
            ans += dp(s, i+2);
        return memo[i] = ans;
    }
};


// Bottom-up DP - Time: O(N), Space: O(N)
class Solution_1 { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp[i] += dp[i+1];
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};

// Bottom-up DP (Space Optimized) - Time: O(N), Space: O(1)
/*
Since our dp only need to keep up to 3 following states:
Current state, let name dp corresponding to dp[i]
Last state, let name dp1 corresponding to dp[i+1]
Last twice state, let name dp2 corresponding to dp[i+2]
So we can achieve O(1) in space.
 */
class Solution_2 { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size(), dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp += dp1;
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};