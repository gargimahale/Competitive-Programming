#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int step = nums[0];
        for (int i = 1; i < n; ++i) {
            steps--;
            if (steps < 0) return false;

            if (nums[i] > steps) {
                steps = nums[i];
            }
        }
        return true;
    }
};

// OR

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxIdxReach = nums[0], limit = nums[0];
        if (n < 2){
            return true;
        }
        for (int i = 0; i < n; ++i){
            if (i > maxIdxReach){
                return false;
            }
            maxIdxReach = max(maxIdxReach, i+nums[i]);
        }
        return true;
    }
};