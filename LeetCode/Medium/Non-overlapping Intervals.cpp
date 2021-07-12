#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;

        sort(begin(intervals), end(intervals), [&](auto a, auto b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        int first = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < first) {
                ++cnt;
            } else {
                first = intervals[i][1];
            }
        }
        return cnt;
    }
};
