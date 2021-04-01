#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findDuplicate(vector<int> &nums){
        for (int x : nums){
            if (nums[abs(x) - 1] < 0)
                return abs(x);
            else
                nums[abs(x) - 1] *= -1;
        }
        return 0;
    }
};
