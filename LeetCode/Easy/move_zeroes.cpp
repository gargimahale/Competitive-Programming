#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), i = 0;
        vector<int> sol;
        for (int x : nums) {
            if (x != 0) {
                nums[i++] = x;
            }
        }

        for (int j = i; j < len; ++j) {
            nums[j] = 0;
        }
        return sol;
    }
};


// OR

class Solution_1 {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0, n = nums.size();
        if (n < 2){
            return;
        }
        int i = 0; 
        while(i < n){
            if (nums[i] != 0){
                swap(nums[st++], nums[i]);
            }
            i++;
        }
    }
};