#include <bits/stdc++.h>
using namespace std;

/*

Explanation:
https://labuladong.gitbook.io/algo-en/iii.-algorithmic-thinking/prefix_sum
 */

// Brute force - O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefSum(n+1, 0);
        int count = 0;
        for (int i = 0; i<n; ++i){
            prefSum[i+1] = prefSum[i] + nums[i];
        }
        
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < i; ++j){
                // sum: nums[j..i-1]
                if (prefSum[i] - prefSum[j] == k){
                    ++count;
                }
            }
        }
        return count;
    }
};

// O(N)
class Solution_1 {
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