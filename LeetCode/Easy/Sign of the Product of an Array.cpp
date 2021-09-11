#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        short ans = 1;
        for (int& x: nums){
            ans *= x < 0 ? -1: x == 0 ? 0: 1;
        }
        return ans;
    }
};