#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution_1 {
    int fact(int& n){
        int f = 1;
        for (int i = 1; i<=n; ++i){
            f *= i;
        }
        return f;
    }

    void next_permutation(vector<int>& nums){
        int k = nums.size()-2;
        while(k >= 0 && nums[k] >= nums[k+1]) --k;

        if (k < 0){
            reverse(begin(nums), end(nums));
        }
        else{
            int start = 0;
            for (start = nums.size()-1; start > k; --start){
                if(nums[k] < nums[start]){
                    break;
                }
            }
            swap(nums[start], nums[k]);
            reverse(begin(nums)+k+1, end(nums));
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (!n) return res;

        n = fact(n);

        for (int i = 0; i<n; ++i){
            res.push_back(nums);
            next_permutation(nums);
        }
        return res;
    }
};

class Solution_2 {
    void helperPermutation(vector<int> nums, int i){
        if (i >= nums.size()){
            res.push_back(nums);
            return;
        }
        
        for (int start = i; start < nums.size(); ++start){
            swap(nums[start], nums[i]);
            helperPermutation(nums, i+1);
            swap(nums[start], nums[i]);
        }
        
    }
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()){
            return res;
        }
        
        helperPermutation(nums, 0);
        return res;
    }
};