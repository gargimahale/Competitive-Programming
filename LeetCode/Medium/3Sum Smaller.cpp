#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        if (nums.size() < 3){
            return 0;
        }
        sort(begin(nums), end(nums));
        for (int i=0; i<nums.size()-2; ++i){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if (nums[i]+nums[j]+nums[k] < target){
                    count+= (k - j++);
                }
                else{
                    --k;
                }
            }
        }
        return count;
    }
};