#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int sum = 0;
        for (int x : nums) sum += x;

        int left = 0, right = sum - nums[0];

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                left += nums[i - 1];
                right -= nums[i];
            }

            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};