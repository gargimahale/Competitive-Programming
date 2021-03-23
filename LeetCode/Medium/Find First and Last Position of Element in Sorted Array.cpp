#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int binSearch(vector<int> &nums, int target, bool check){
        int l = 0, h = nums.size() - 1, ans = -1;
        while (l <= h){
            int m = (h - l) / 2 + l;
            if (nums[m] == target){
                ans = m;
                if (!check)
                    h = m - 1;
                else
                    l = m + 1;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                h = m - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target){
        int first = binSearch(nums, target, false);
        int second = binSearch(nums, target, true);
        return {first, second};
    }
};