#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int k = nums.size() - 2;
        // found k
        while (k >= 0 && nums[k] >= nums[k + 1]) --k;

        if (k < 0) {
            reverse(begin(nums), end(nums));
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
        }
    }

    int fact(int n) {
        int ans = 1;
        while (n > 1) {
            ans *= n--;
        }
        return ans;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<vector<int>> res;
        n = fact(n);
        for (int i = 0; i < n; ++i) {
            res.push_back(nums);
            nextPermutation(nums);
        }

        return res;
    }
};

// TC: O(N!), SC: O(N!)