#include <bits/stdc++.h>

using namespace std;

// TC: O(nlogn), SC: O(1)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (auto i = 0, lhs = 0, cnt1 = 0, cnt2 = 0; i <= nums.size(); ++i) {
            if (i == nums.size()) {
                return lhs;
            }

            if (i == 0 || nums[i] == nums[i - 1]) {
                ++cnt1;
            }
            else {
                cnt2 = (nums[i - 1] + 1 == nums[i]) ? cnt1 : 0, cnt1 = 1;
            }

            if (cnt1 > 0 && cnt2 > 0) {
                lhs = max(lhs, cnt1 + cnt2);
            }
        }
        return 0;
    }
};