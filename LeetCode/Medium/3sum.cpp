#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3){
            return {};
        }

        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-2; ++i){
            if (i == 0 || nums[i] != nums[i-1]){
                int j = i+1, k = nums.size()-1;
                while(j<k){
                    int sum = nums[i]+nums[j]+nums[k];
                    if (sum == 0){
                        res.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j+1]) j++;
                        while(j < 0 && nums[k] == nums[k-1]) k--;
                        j++, k--;
                    }
                    else if (sum > 0){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        return res;
    }
};