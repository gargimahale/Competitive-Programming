#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> nums(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            nums[i] =  __builtin_popcount(i);
        return nums;
    }
};

// TC: O(n), SC: O