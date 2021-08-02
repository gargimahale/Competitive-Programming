#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> U (begin(days), end(days));
        int dp[30] = {};

        for (int i = days.front(); i <= days.back(); ++i) {
            if (U.find(i) == U.end()) dp[i % 30] = dp[(i - 1) % 30];
            else {
                dp[i % 30] = min({dp[(i - 1) % 30] + costs[0], dp[max(0, i - 7) % 30] + costs[1], dp[max(0, i - 30) % 30] + costs[2]});
            }
        }
        return dp[days.back() % 30];
    }
};

// TC:O(days), SC: O(30)

// OR
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> S(begin(days), end(days));
        vector<int> dp(366);

        for (int i = 1; i < 366; ++i) {
            if (S.find(i) == S.end()) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[365];
    }
};

// TC: O(days), SC: O(365)