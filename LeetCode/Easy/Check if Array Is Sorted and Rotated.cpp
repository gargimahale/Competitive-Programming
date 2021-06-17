#include <bits/stdc++.h>

using namespace std;


/*
Compare all neignbour elements (a,b) in A,
the case of a > b can happen at most once.

Note that the first element and the last element are also connected.

If all a <= b, A is already sorted.
If all a <= b but only one a > b,
we can rotate and make b the first element.
Other case, return false.

*/

class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i = 0, k = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[(i + 1) % nums.size()] && ++k > 1) {
                return false;
            }
        }
        return true;
    }
};