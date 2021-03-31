#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minCost(string s, vector<int> &cost){
        int res = 0, maxCost = 0, n = s.size();
        for (int i = 0; i < n; ++i){
            if (i > 0 && s[i] != s[i - 1])
                maxCost = 0;
            res += min(maxCost, cost[i]);
            maxCost = max(maxCost, cost[i]);
        }
        return res;
    }
};