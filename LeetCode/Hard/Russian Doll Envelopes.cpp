#include <bits/stdc++.h>
using namespace std;

// Tc: O(nlogn), SC: O(n)

class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& env) {
        int n = env.size();

        if (n == 0) return 0;

        sort(begin(env), end(env), [&](auto x, auto y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
        });

        vector<int> dp;
        for (auto x : env) {
            auto it = lower_bound(begin(dp), end(dp), x[1]);
            if (it == dp.end()) dp.push_back(x[1]);
            else if (x[1] < *it) *it = x[1];
        }
        return dp.size();
    }
};
