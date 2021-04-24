#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int i = 0, j = 0, win = 0, res = 0;
        unordered_set<int> S;
        for (int i = 0, j = 0, win = 0; j < n; ++j){
            while(S.find(nums[j]) != S.end()){
                S.erase(nums[i]);
                win -= nums[i++];
            }
            S.insert(nums[j]);
            win += nums[j];
            res = max(res, win);
        }
        return res;
    }
};