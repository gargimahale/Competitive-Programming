#include <bits/stdc++.h>
using namespace std;

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> vec;
        if(schedule.empty() || schedule[0].empty()) return vec;
        for(auto &a:schedule) vec.insert(vec.end(), a.begin(),a.end());
        sort(vec.begin(),vec.end(),[](auto &a, auto &b){return a.start<b.start ||(a.start == b.start && a.end<b.end);});
        vector<Interval> res;
        int end = vec[0].end;
        for(int i =1 ; i < vec.size(); ++i){
            
            if(vec[i].start <= end)
                end = max(end,vec[i].end);
            else{
                res.push_back(Interval(end,vec[i].start));
                end = vec[i].end;
            }
            
        }
        return res;
    }
};