#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> Q;
        vector<int> dir = { -1, 0, 1, 0, -1};
        int fresh = 0;
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh;
                }
                if (grid[i][j] == 2) {
                    Q.push({i, j});
                }
            }
        }

        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto ele = Q.front();
                Q.pop();
                for (int d = 0; d < 4; ++d) {
                    int r = ele.first + dir[d];
                    int c = ele.second + dir[d + 1];

                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        Q.push({r, c});
                        --fresh;
                    }
                }
            }
            ++ans;
        }

        if (fresh > 0) return -1;
        if (ans == -1) return 0;
        return ans;
    }
};

// TC: O(N*M)
// SC: O(N)