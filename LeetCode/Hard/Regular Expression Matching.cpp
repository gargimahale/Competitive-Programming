#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if (n == 0) return (m == 0);
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));

        // Empty string matxhes empty pattern
        dp[0][0] = true;
        
        for (int j = 1; j <= m; ++j){
            dp[0][j] = p[j-1] == '*' && dp[0][j-2];
        }
        
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
            	// if the current characters match or pattern has . then the result 
            	// is determined by the previous state dp[i][j] = dp[i-1][j-1]
                if (s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }

                // if p[j-1] == '*' then either it acts as an empty set and the 
                // result is dp[i][j] = dp[i][j-2] or (s[i-1] == p[j-2] || p[j-2] == '.') 
                // current char of string equals the char preceding * in pattern so the result is dp[i-1][j]
                else if (p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);    
                }
            }
        }
        return dp[n][m];
    }
};