#include <bits/stdc++.h>
using namespace std;

// TC: O(log(min(x, y))), SC: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;
        while (low <= high) {
            int partitionX = low + (high - low) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            double maxLeftX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
            double maxLeftY = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];

            double minRightX = partitionX == x ? INT_MAX : nums1[partitionX];
            double minRightY = partitionY == y ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
                return max(maxLeftX, maxLeftY);
            }

            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            else {
                low = partitionX + 1;
            }
        }
        return -1;
    }
};

int main(void) {
    Solution sol;
    vector<int> a = {23, 26, 31, 35};
    vector<int> b = {3, 5, 7, 9, 11, 16};
    cout << sol.findMedianSortedArrays(a, b) << "\n";
}

// Explanation: https://www.youtube.com/watch?v=LPFhl65R7ww&ab_channel=TusharRoy-CodingMadeSimpleTusharRoy-CodingMadeSimple
// Tushar Roy