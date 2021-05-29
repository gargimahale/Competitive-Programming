#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n, 0);
        int sz = 0, prev, temp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                temp = dp[j];
                if (!i || !j || matrix[i][j] == '0') {
                    dp[j] = matrix[i][j] - '0';
                }
                else {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                }
                sz = max(sz, dp[j]);
                prev = temp;
            }

        }
        return sz * sz;
    }
};
*/

// TC: O(NM), SC: O(NM)
// Opimization: Just store row vector

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n, 0);
        int sz = 0, prev, temp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                temp = dp[j];
                if (!i || !j || matrix[i][j] == '0') {
                    dp[j] = matrix[i][j] - '0';
                }
                else {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                }
                sz = max(sz, dp[j]);
                prev = temp;
            }

        }
        return sz * sz;
    }
};

// TC: O(NM), SC: O(M)

int main(void) {
    Solution sol;
    vector<vector<char>> mat = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << sol.maximalSquare(mat) << "\n";
}