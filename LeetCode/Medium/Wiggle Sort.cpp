#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i){
            if ((!(i%2) && nums[i-1] < nums[i]) || ((i%2) && nums[i-1] > nums[i])){
                swap(nums[i], nums[i-1]);
            }
        }
    }
};