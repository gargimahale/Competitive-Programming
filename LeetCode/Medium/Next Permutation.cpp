#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int k = nums.size() - 2;

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
};

int main(void) {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> ans = sol.nextPermutation(nums);
    for (int x : ans) cout << x << " ";
    cout << "\n";
}