#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int p = 0, c = 0;
        for (int i=0; i<nums.size(); ++i){
            int temp = max(p+nums[i], c);
            p = c;
            c = temp;
        }
        return c;
    }
};
