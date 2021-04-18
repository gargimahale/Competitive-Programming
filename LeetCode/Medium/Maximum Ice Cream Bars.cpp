#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        if (costs.size() == 0 || coins == 0) return 0;

        sort(begin(costs), end(costs));

        int cnt = 0;

        for (int x : costs) {
            if (coins - x >= 0) {
                ++cnt;
                coins -= x;
            }
        }
        return cnt;
    }
};