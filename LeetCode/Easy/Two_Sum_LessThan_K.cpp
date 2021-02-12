#include <bits/stdc++.h>

using namespace std;

// Two pointer or the otherwise known as binary search method

class Solution
{
public:
    int twoSumLessThanK(vector<int> &nums, int k)
    {
        int largestSum = -1;
        sort(begin(nums), end(nums)); // nlogn
        for (int i = 0, j = nums.size() - 1; i < j;)
        {
            if (nums[i] + nums[j] < k)
            {
                largestSum = max(largestSum, nums[i++] + nums[j]);
            }
            else
            {
                j--;
            }
        }
        return largestSum;
    }
};