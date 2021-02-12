#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nearestSum = 0;
        int mindiff = INT_MAX;
        if (nums.size() < 3){
            return nearestSum;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if (abs(sum - target) < mindiff){
                    nearestSum = sum;
                    mindiff = abs(sum - target);
                }
                else if (sum > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return nearestSum;
    }
};