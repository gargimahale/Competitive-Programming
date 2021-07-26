#include <bits/stdc++.h>
using namepsace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) const {
        int res = 0, n = nums.size();
        vector<bool> seen(n, false);
        for (int& x : nums) {
            int cnt = 0;
            while (!seen[x]) {
                ++cnt;
                seen[x] = true;
                x = nums[x];
            }
            res = max(res, cnt);
        }
        return res;
    }
};