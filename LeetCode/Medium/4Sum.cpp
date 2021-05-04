#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n<4){
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i){
            int check3 = target - nums[i];
            for (int j = i+1; j<n; ++j){
                int check2 = check3 - nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    int sum = nums[low]+nums[high];
                    if (sum > check2){
                        --high;
                    }
                    else if (sum < check2){
                        ++low;
                    }
                    else{
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[low];
                        quad[3] = nums[high];
                        res.push_back(quad);
                        
                        // duplicates for number 3
                        while(low < high && nums[low] == quad[2]){
                            ++low;
                        }
                        
                        // duplicates for number 4
                        while(low < high && nums[high] == quad[3]){
                            --high;
                        }
                    }
                }
                // duplicates for number 2
                while(j+1 < n && nums[j+1] == nums[j]){
                    ++j;
                }
            }
            // duplicates for number 1
            while(i+1 < n && nums[i+1] == nums[i]){
                ++i;
            }
        }
        return res;
    }
};