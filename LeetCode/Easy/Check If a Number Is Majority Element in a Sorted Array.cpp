#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for (int x : nums) {
            cnt += x == target;
        }

        return cnt > n / 2;
    }
};

// TC: O(N)
// SC: O(1)