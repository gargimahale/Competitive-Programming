#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int jumps = 1, currEnd = nums[0], currFarthest = nums[0];
        for (int i = 1; i < n; ++i) {
            if (i > currEnd) {
                ++jumps;
                currEnd = currFarthest;

                if (currFarthest >= n - 1) {
                    break;
                }
            }
            currFarthest = max(currFarthest, i + nums[i]);
        }
        return jumps;
    }
};


// TC: O(N), SC: O(1)