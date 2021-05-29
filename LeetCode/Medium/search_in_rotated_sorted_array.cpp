#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // Search in the right half
            if (nums[mid] <= nums[high]) {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            // search in the left half
            else {
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};

// TC: O(log N)
// SC: O(1)