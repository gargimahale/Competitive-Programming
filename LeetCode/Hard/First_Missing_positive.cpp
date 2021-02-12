#include <bits/stdc++.h>

using namespace std;

// TC: O(n), SC: O(n)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool found_one = false;
        int n = nums.size();
        unordered_map<int, int>map;
        for(int x: nums){
            if (x > 0 && x <= nums.size()){
                map[x]++;
            }
            if (x == 1){
                found_one = true;
            }
        }
        
        if (!found_one){
            return 1;
        }
        
        //finding the number
        for(int i=2; i<=n; ++i){
            if (map.find(i) == map.end()){
                return i;
            }
        }
        return n+1;
    }
};

// TC: O(n), SC: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool found_one = false;
        int n = nums.size();
        for(int x: nums){
            if (x == 1){
                found_one = true;
                break;
            }
        }
        
        if (!found_one){
            return 1;
        }
        for(int i=0; i<n; ++i){
            if (nums[i] > n || nums[i] <= 0){
                nums[i] = 1;
            }
        }
        
        for(int i=0; i<n; ++i){
            int x = abs(nums[i]);
            if(nums[x-1] > 0){
                nums[x-1] *= -1;
            }
        }
        for (int i=0; i<n; ++i){
            if (nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};
