#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), step = nums[0];
        if (n == 0){
            return false;
        }
        for(int i=1; i<n; ++i){
            step--;
            if (step < 0){
                return false;
            }
            if (nums[i] > step){
                step = nums[i];
            }
        }
        return true;
    }
};