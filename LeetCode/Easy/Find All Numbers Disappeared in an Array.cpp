#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
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

        // find the missing element
        for (int i = 0; i < n; ++i)
        {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0)
            {
                nums[x - 1] *= -1;
            }
        }

        // add elements to the array
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};