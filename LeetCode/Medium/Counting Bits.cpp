#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> countBits(int num){
        vector<int> nums(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            nums[i] = nums[i / 2] + i % 2;
        return nums;
    }
};