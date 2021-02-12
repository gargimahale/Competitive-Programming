#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (int i=0; i<nums.size(); ++i){
            for (int j=0; j<i; ++j){
                int prod = nums[i] * nums[j];
                res += 8*m[prod];
                ++m[prod];
            }
        }
        return res;
    }
};