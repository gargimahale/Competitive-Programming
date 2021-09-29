#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if (n == 0) return (m == 0);
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        
        for (int j = 2; j <= m; ++j){
            dp[0][j] = p[j-1] == '*' && dp[0][j-2];
        }
        
        for (int j = 1; j <= m; ++j){
            for (int i = 1; i <= n; ++i){
                if (s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);    
                }
            }
        }
        return dp[n][m];
    }
};