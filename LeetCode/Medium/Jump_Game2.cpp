#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>nums) {
        int n = nums.size(), start = 0, end = 0, steps = 0;
        while (end < n - 1) {
            steps++;
            int maxend = end + 1;
            for (int i = start; i <= end; ++i) {
                if (i + nums[i] >= n - 1) return steps;
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        return steps;
    }
};