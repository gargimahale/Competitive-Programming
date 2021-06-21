#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int partition = 0, len = nums.size();
        int local_max = nums[0], global_max = nums[0];

        for (int i = 1; i < len; ++i) {
            if (nums[i] < local_max) {
                partition = i;
                local_max = global_max;
            }
            else {
                global_max = max(global_max, nums[i]);
            }
        }
        return partition + 1;
    }
};