#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        // <prefixSum, Count>
        unordered_map<int, int> mp;
        int count = 0, prefixSum = 0;

        int i = 0;
        while (i < n) {
            prefixSum += nums[i];
            if (prefixSum == k) {
                ++count;
            }

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
            ++i;
        }
        return count;
    }
};

// TC: O(N), SC: O(N)