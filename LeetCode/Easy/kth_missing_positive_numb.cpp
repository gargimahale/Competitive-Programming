#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] - 1 - mid < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};
