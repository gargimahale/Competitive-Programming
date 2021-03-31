#include<bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution{
public:
    void rotate(vector<int> &nums, int k){
        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums) + (k % nums.size()));
        reverse(begin(nums) + (k % nums.size()), end(nums));
    }
};