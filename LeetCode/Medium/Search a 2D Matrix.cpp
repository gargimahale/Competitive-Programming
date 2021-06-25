#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        if (mat.empty() || mat[0].empty()) {
            return false;
        }

        int m = mat.size(), n = mat[0].size();
        int start = 0, end = m * n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ele = mat[mid / n][mid % n];

            if (ele == target) {
                return true;
            }
            else if (target > ele) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};