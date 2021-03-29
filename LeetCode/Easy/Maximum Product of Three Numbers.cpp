#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)

class Solution{
public:
    int maximumProduct(vector<int> &nums){

        int n = nums.size();
        if (n < 3)
            return 0;

        sort(nums.begin(), nums.end());
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
