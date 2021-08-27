#include <vector>
using namespace std;

class Solution {
public:

    // Time: O(N*M), Space: O(N*M)
    int maximalSquare_2d(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }


    int maximalSquare_1d(vector<vector<char>>& matrix) {
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