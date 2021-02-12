#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return true;
        }
        
        sort(begin(intervals), end(intervals));
        
        int cnt = 1;
        int start = intervals[0][0], end = intervals[0][1];
        
        for (int i=1; i<intervals.size(); ++i){
            if (intervals[i][0] >= end && intervals[i][1] > end){
                start = intervals[i][0];
                end = intervals[i][1];
                ++cnt;
            }
        }
        
        return cnt == intervals.size();
    }
};