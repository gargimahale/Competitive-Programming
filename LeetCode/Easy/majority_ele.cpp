#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int x : nums) {
            if (count == 0) {
                count = 0;
                candidate = x;
            }
            count += (candidate == x ? 1 : -1);
        }
        return candidate;
    }
};


int main(void) {
    Solution sol;
    vector<int> nums = {3, 3, 4};
    cout << sol.solve(nums);
}
// TC: O(N), SC: O(1)