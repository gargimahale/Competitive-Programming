#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        return nums[nums.size()-k];
    }
};


// OR

class Solution{
public:
    int findKthLargest(vector<int> &nums, int k){
        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &x : nums){
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
