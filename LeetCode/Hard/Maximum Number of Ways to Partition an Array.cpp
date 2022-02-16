#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        long sum = accumulate(begin(nums), end(nums), 0ll), N = nums.size(), ans = 0;
        unordered_map<long, int> L, R;
        
        for (long i = 0, left = 0; i < N-1; ++i){
            left += nums[i];
            long right = sum - left;
            R[left-right]++;
        }
        
        // If we don't do any replacement, answer is the number of `0`s in the frequency map
        ans = R[0];
        
        for (long i = 0, left = 0; i < N; ++i){
            left += nums[i];
            long right = sum - left, d = k - nums[i];
            
            // If we replace `A[i]` with `k`, we will get `L[d] + R[-d]` pivots
            ans = max(ans, (long)L[d]+R[-d]);
            R[left - right]--; // transfer the frequency from `R` to `L`.
            L[left - right]++;
        }
        
        return ans;
    }
};