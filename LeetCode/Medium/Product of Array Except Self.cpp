#include <bits/stdc++.h>
using namespace std;

/*
Given numbers [2, 3, 4, 5], regarding the third number 4, the product of array except 4 is 2*3*5 which
consists of two parts: left 2*3 and right 5. The product is left*right. We can get lefts and rights:

Numbers:     2    3    4     5
Lefts:            2  2*3 2*3*4
Rights:  3*4*5  4*5    5

Let’s fill the empty with 1:
Numbers:     2    3    4     5
Lefts:       1    2  2*3 2*3*4
Rights:  3*4*5  4*5    5     1
We can calculate lefts and rights in 2 loops. The time complexity is O(n).

We store lefts in result array. If we allocate a new array for rights. The space complexity is O(n).
To make it O(1), we just need to store it in a variable which is right
 */


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1, right = 1;

        // left
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                left = left * nums[i - 1];
            }
            res[i] = left;
        }

        //right
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1) {
                right = right * nums[i + 1];
            }
            res[i] *= right;
        }

        return res;
    }
};