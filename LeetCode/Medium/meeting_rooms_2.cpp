#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        pq.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++) {
            if (pq.top() <= intervals[i][0]) pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};

// OR

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for (auto& t : intervals) {
            mp[t[0]]++, mp[t[1]]--;
        }

        int res = 0, curr = 0;
        for (auto it : mp) {
            res = max(res, curr += it.second);
        }

        return res;
    }
};