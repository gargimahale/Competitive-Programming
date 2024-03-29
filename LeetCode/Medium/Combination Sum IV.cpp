#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> comb(target + 1);

        comb[0] = 1;
        for (int i = 1; i < comb.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i - nums[j] >= 0) {
                    comb[i] += comb[i - nums[j]];
                }
            }
        }
        return comb[target];
    }
};