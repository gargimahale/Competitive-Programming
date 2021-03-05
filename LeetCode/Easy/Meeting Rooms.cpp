#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0) return 1;

        int cnt = 1;
        sort(begin(intervals), end(intervals));

        for (int i=1; i<n; ++i){
            if (intervals[i][0] < intervals[i-1][1]) return false;
            ++cnt;
        }
        return true;
    }
};