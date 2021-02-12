#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int maxVal = INT_MIN;
        for (int i=0; i<nums.size(); ++i){
            maxVal = max(maxVal, prod*=nums[i]);
            if (nums[i] == 0){
                prod = 1;
            }
        }

        prod = 1;
        for (int i=nums.size()-1; i>=0; --i){
            maxVal = max(maxVal, prod*=nums[i]);
            if (nums[i] == 0){
                prod = 1;
            }
        }
        return maxVal;
    }
};