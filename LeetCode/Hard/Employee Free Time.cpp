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
        for (auto& s : schedule) vec.insert(vec.end(), s.begin(), s.end());
        
        sort(begin(vec), end(vec), [&](auto a, auto b){
            return a.start < b.start || (a.start == b.start && a.end < b.end);
        });
        
        vector<Interval> res;
        int end = vec[0].end;
        
        for (int i=1; i<vec.size(); ++i){
            if (vec[i].start <= end){
                end = max(vec[i].end, end);
            }
            else{
                res.push_back(Interval(end, vec[i].start));
                end = vec[i].end;
            }
        }
        return res;
    }
};