#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr1 = 0, prev = 0, curr2 = 0;

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        for (int i = 0; i < n - 1; ++i) {
            int temp = max(nums[i] + prev, curr1);
            prev = curr1;
            curr1 = temp;
        }

        prev = 0;
        for (int i = 1; i < n; ++i) {
            int temp = max(nums[i] + prev, curr2);
            prev = curr2;
            curr2 = temp;
        }
        return max(curr1, curr2);
    }
};