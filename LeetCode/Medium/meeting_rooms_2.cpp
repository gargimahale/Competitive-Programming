#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:

    // Time: O(NlogN), Space: O(N)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1){
            return n;
        }
        
        sort(begin(intervals), end(intervals));
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (auto& interval: intervals){
            if (!min_heap.empty() && min_heap.top() <= interval[0]){
                min_heap.pop();
            }
            min_heap.push(interval[1]);
        }
        return min_heap.size();
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