#include <bits/stdc++.h>
using namespace std;


/*--------------------------------------------------------------------------------------------------
I use the variables beg and end to keep track of minimum subarray A[beg...end] which must be sorted 
for the entire array A to be sorted. If end < beg < 0 at the end of the for loop, then the array 
is already fully sorted.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), end = -2, begin = -1, minEle = nums[n-1], maxEle = nums[0];
        
        for (int i = 1; i < n; ++i){
            minEle = min(minEle, nums[n-i-1]);    // from right to left, search the current min 
            maxEle = max(maxEle, nums[i]);  // from left to right, search the current max
            if (nums[i] < maxEle) end = i;
            if (nums[n-i-1] > minEle) begin = n-i-1;
        }

        // will return 0 if the array is sorted
        return end - begin + 1;
    }
};