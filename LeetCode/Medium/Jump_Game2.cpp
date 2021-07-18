#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jumps = 0, currEnd = 0, currFarthest = 0;

        if (n <= 1) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            currFarthest = max(currFarthest, i + nums[i]);
            if (i == currEnd) {
                ++jumps;
                currEnd = currFarthest;

                if (currFarthest >= n - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};

