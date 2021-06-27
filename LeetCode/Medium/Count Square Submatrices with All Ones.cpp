#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] && i && j) {
                    matrix[i][j] = min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]}) + 1;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};