#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= m; ++i) {
            dp[0][i] = i;
        }

        for (int j = 0; j <= n; ++j) {
            dp[j][0] = j;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[n][m];
    }

    int minDistanceOptimized_1(string& word1, string& word2){
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for (int j = 1; j <= m; ++j) prev[j] = j;
        
        for(int i = 1; i <= n; ++i){
            curr[0] = i;
            for (int j = 1; j <= m; ++j){
                if (word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = min({curr[j-1], prev[j], prev[j-1]}) + 1;
                }
            }
            
            fill(prev.begin(), prev.end(), 0);
            swap(curr, prev);
        }
        return prev[m];
    }
};

int main(void) {
    Solution sol;
    string a = "horse", b = "ros";
    cout << sol.minDistance(a, b) << "\n";
}