#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] *= -1;
            }
            else return abs(nums[i]);
        }
        return 0;
    }
};

// OR
// Hare and Tortoise Method

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n > 1) {
            int slow = nums[0], fast = nums[nums[0]];

            while (fast != slow) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }

            return slow;
        }
        return -1;
    }
};