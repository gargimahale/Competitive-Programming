#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size(), k = days[0].size(); // n city , k weeks
        vector<vector<int>> dp(n, vector<int>(k, 0)); // dp[i][j] - max days play if you spent week j in city i;
        for (int j = k - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = days[i][j];
                for (int i1 = 0; i1 < n && j < k - 1; i1++) {
                    if (flights[i][i1] || i == i1)
                        dp[i][j] = max(dp[i][j], days[i][j] + dp[i1][j + 1]);
                }
            }
        }
        int maxplay = dp[0][0];
        for (int i = 1; i < n; i++) {
            if (flights[0][i]) {
                maxplay = max(maxplay, dp[i][0]);
            }
        }
        return maxplay;
    }
};