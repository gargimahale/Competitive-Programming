#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1e9+7, dp[2] = {0, 0};
        
        for (char& ch: binary){
            dp[ch-'0'] = (dp[0] + dp[1] + ch -'0') % mod;
        }
        
        return dp[0] + dp[1] + ((binary.find("0") != string::npos)) % mod;
    }
};
