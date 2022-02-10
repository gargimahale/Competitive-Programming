#include <bits/stdc++.h>
using namespace std;

// Time: O(NlogN), Space: O(logN)
vector<int> maxSlidingWindow_queue(vector<int>& nums, int k) {
    vector<int> res;

    priority_queue<pair<int, int>> heap;

    for (int i = 0; i<nums.size(); ++i){
        while(!heap.empty() && heap.top().second <= (i-k)){
            heap.pop();
        }

        heap.push({nums[i], i});

        if (i >= k-1){
            res.push_back(heap.top().first);
        }
    }
    return res;
}


vector<int> maxSlidingWindow_dq(vector<int>& nums, int k) {
    vector<int> res;
    deque<pair<int, int>> dq;

    for (int i = 0; i<nums.size(); ++i){
        while (!dq.empty() && dq.front().second <= (i-k)){
            dq.pop_front();
        }

        while(!dq.empty() && dq.back().first < nums[i]){
            dq.pop_back();
        }

        dq.push_back({nums[i], i});

        if (i >= k-1){
            res.push_back(dq.front().first);
        }
    }
    return res;
}