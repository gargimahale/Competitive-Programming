#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int minSideJumps(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        int dp[n][3];
        dp[0][1] = 0;
        dp[0][0] = dp[0][2] = 1;

        for (int i = 1; i < n; ++i)
        {
            for (int r = 0; r < 3; ++r)
            {
                if (obstacles[i] == r + 1 || obstacles[i + 1] == r + 1)
                    dp[i][r] = n;
                else
                    dp[i][r] = min(dp[i - 1][r], min(dp[i - 1][(r + 1) % 3], dp[i - 1][(r + 2) % 3]) + 1);
            }
        }

        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};
