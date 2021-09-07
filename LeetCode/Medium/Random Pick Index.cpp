#include <bits/stdc++.h>
using namespace std;


// Time: O(N) Space: O(N)
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int>& nums) {
        for (int i = 0; i<nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> idx = mp[target];
        return idx[rand() % idx.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// Time: O(N), Space: O(1)
// Reservoir Sampling
// Ref: https://www.youtube.com/watch?v=A1iwzSew5QY&ab_channel=EricLaber
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int count = 0, idx = 0;
        for (int i = 0; i<nums.size(); ++i){
            if (nums[i] == target){
                ++count;
                if (rand() % count == 0){
                    idx = i;
                }
            }
        }
        return idx;
    }
};