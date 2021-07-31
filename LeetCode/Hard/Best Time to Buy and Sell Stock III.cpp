#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n < 2) return 0;

        vector<int> profit1(n, 0), profit2(n, 0);
        int p1 = prices[0], p2 = prices[n - 1];

        for (int i = 1; i < n; ++i) {
            profit1[i] = max(profit1[i - 1], prices[i] - p1);
            p1 = min(p1, prices[i]);

            int j = n - i - 1;
            profit2[j] = max(profit2[j + 1], p2 - prices[j]);
            p2 = max(p2, prices[j]);
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans = max(ans, profit1[i] + profit2[i]);
        }
        return ans;
    }
};