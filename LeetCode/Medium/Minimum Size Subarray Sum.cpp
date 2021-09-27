#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n+1, 0);
        
        // prefix Sum
        for (int i = 1; i<=n; ++i){
            sums[i] = sums[i-1] + nums[i-1];
        }
        
        int len = INT_MAX;
        for (int i = n; i >= 0 && sums[i] >= target; --i){
            int j = upper_bound(begin(sums), end(sums), sums[i]-target) - begin(sums);
            
            len = min(len, i - j + 1);
        }
        
        return len == INT_MAX ? 0: len;
    }
};