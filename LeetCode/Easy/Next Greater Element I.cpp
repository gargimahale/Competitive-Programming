#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int m = findNums.size(), n = nums.size();
        stack<int> s;
        unordered_map<int, int> mp;

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            while (s.size() && s.top() < nums[i]) {
                mp[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }

        for (int x : findNums) {
            res.push_back(mp.count(x) ? mp[x] : -1);
        }
        return res;
    }
};

// TC: O(N), SC: O(N)