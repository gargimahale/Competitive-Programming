#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                count += i != j && nums[i] + nums[j] == target;
            }
        }
        return count;
    }
};