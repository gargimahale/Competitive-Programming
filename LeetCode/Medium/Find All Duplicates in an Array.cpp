#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1) - if the output array is excluded

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        vector<int> ans;
        int n = nums.size();

        // normalise
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = 1;
            }
        }

        // find the repeated elements
        for (int i = 0; i < n; ++i)
        {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0)
            {
                nums[x - 1] *= -1;
                continue;
            }
            ans.push_back(abs(x));
        }

        return ans;
    }
};