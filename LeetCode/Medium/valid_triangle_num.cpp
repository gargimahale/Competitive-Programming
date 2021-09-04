#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for ( int k = n - 1; k > 1; --k ) {
            int i = 0, j = k - 1;
            while ( i < j ) {
                if (nums[i] + nums[j] > nums[k])
                    count += --j - i + 1;
                else
                    ++i;
            }
        }
        return count;
    }
};
