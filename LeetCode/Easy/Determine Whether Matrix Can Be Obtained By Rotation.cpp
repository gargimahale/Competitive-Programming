#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int deg = 3, n = mat.size();
        if (mat == target) return true;

        while (deg--) {
            reverse(begin(mat), end(mat));

            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};