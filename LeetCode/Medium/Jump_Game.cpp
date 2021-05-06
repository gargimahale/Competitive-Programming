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