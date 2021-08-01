#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool nextPermuatation(vector<int>& nums) {
        int k = nums.size() - 2;
        while (k >= 0 && nums[k] >= nums[k + 1]) --k;

        if (k < 0) {
            reverse(begin(nums), end(nums));
            return false;
        }
        else {
            int i = 0;
            for (i = nums.size() - 1; i > k; --i) {
                if (nums[i] > nums[k]) {
                    break;
                }
            }
            swap(nums[i], nums[k]);
            reverse(begin(nums) + k + 1, end(nums));
            return true;
        }
    }
public:
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(begin(nums), end(nums));

        do {
            ans.push_back(nums);
        } while (nextPermuatation(nums));

        return ans;
    }
};