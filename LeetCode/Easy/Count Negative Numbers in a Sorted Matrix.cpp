#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(const vector<vector<int>>& grid) {
        int cnt = 0;
        for (auto& row : grid) {
            cnt += upper_bound(rbegin(row), rend(row), -1) - rbegin(row);
        }
        return cnt;
    }
};

// TC: O(N logN), SC: O(1)