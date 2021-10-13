#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    
    // Time: O(NlogN), Space: O(N)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2){
            return n;
        }
        sort(begin(intervals), end(intervals));
        priority_queue<int> pq;
        pq.push(-intervals[0][1]);
        
        for (int i = 1; i < n; ++i){
            if (intervals[i][0] >= -pq.top()){
                pq.pop();
            }
            
            pq.push(-intervals[i][1]);
        }
        return pq.size();
    }

    // Time: O(NlogN), Space: O(N)
    int minMeetingRooms_1(vector<vector<int>>& intervals) {
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