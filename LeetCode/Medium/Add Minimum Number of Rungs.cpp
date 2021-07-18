#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addRungs(const vector<int>& rungs, const int& dist) {
        int res = (rungs[0] - 1) / dist;
        for (int i = 1; i < rungs.size(); ++i) {
            res += (rungs[i] - rungs[i - 1] - 1) / dist;
        }
        return res;
    }
};