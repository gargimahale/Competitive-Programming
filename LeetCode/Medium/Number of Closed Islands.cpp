#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        if (grid[i][j] == 1) return true;

        grid[i][j] = 1;
        bool a = dfs(grid, i + 1, j);
        bool b = dfs(grid, i - 1, j);
        bool c = dfs(grid, i, j + 1);
        bool d = dfs(grid, i, j - 1);

        return a && b && c && d;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) {
                    res += dfs(grid, i, j) ? 1 : 0;
                }
            }
        }
        return res;
    }
};