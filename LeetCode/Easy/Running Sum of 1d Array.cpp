#include <bits/stdc++.h>
using namespace std;

// Tc: O(n), SC: O(1)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if (nums.size() == 0) return nums;
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};