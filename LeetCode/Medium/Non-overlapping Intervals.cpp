#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if (intervals.empty()){
            return 0;
        }
        
        sort(begin(intervals), end(intervals));
        int cnt = 1, end = intervals[0][1];
        
        for (auto& p: intervals){
            if (end > p[0]){
                end = min(end, p[1]);
            }
            else{
                end = p[1];
                ++cnt;
            }
        }
        return intervals.size() - cnt;
    }
};

