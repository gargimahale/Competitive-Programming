#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        if (matrix.size() == 0) return sol;

        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int size = matrix[0].size() * matrix.size();
        while (sol.size() < size) {
            for (int i = left; i <= right && sol.size() < size; ++i) {
                sol.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom && sol.size() < size; ++i) {
                sol.push_back(matrix[i][right]);
            }
            right--;

            for (int i = right; i >= left && sol.size() < size; --i) {
                sol.push_back(matrix[bottom][i]);
            }
            bottom--;

            for (int i = bottom; i >= top && sol.size() < size; --i) {
                sol.push_back(matrix[i][left]);
            }
            left++;
        }
        return sol;
    }
};