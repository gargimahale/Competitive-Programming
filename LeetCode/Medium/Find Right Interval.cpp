#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return { -1};
        vector<int> res(n);

        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[intervals[i][0]] = i;
        }

        for (int i = 0; i < n; ++i) {
            auto it = mp.lower_bound(intervals[i][1]);
            res[i] = it != mp.end() ? it->second : -1;
        }

        return res;
    }
};