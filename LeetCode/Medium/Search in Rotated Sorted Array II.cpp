#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // target found
            if (nums[mid] == target) {
                return true;
            }

            // to reduce the number of duplicate checks
            else if (nums[right] == nums[mid]) {
                --right;
            }

            else if (nums[mid] < nums[right]) {
                // normal binary search
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            else {
                // rotated search
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};