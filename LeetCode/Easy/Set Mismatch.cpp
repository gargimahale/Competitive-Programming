#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int sum = 0, n = nums.size(), i;
        vector<int> count(n + 1);
        for (i = 0; i < n; ++i) {
            sum += nums[i];
            count[nums[i]]++;
            if (count[nums[i]] > 1) {
                ans[0] = nums[i];
                break;
            }
        }

        // i++ is done initailly to skip that duplicate number
        for (i++; i < n; ++i) {
            sum += nums[i];
        }

        ans[1] = ((n * (n + 1) / 2) - sum + ans[0]);
        return ans;
    }
};