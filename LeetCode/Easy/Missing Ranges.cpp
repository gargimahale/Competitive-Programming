#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    string getRange(int l, int h){
        return l == h ? to_string(l) : to_string(l) + "->" + to_string(h);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int prev = lower-1;
        for (int i=0; i<=nums.size(); ++i){
            int curr = (i == nums.size() ? upper+1: nums[i]);
            if (curr-prev >= 2){
                res.push_back(getRange(prev+1, curr-1));
            }
            prev = curr;
        }
        return res;
    }
};