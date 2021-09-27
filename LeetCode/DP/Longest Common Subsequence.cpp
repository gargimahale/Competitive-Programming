#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size(), b = text2.size();
        vector<vector<int>> dp (a+1, vector<int> (b+1));
        for (int i = 1; i <= a; ++i){
            for(int j = 1; j <= b; ++j){
                if (text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    // skip char either from text1 or text2
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[a][b];
    }
};

int main(void) {
    Solution sol;
    string a = "abcdaf", b = "acbcf";
    cout << sol.longestCommonSubsequence(a, b);
}