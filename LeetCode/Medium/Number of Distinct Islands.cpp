#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        unordered_set<string> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    string island;
                    distinct(grid, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
private:
    void distinct(vector<vector<int>>& grid, int i, int j, int r, int c, string& island) {
        int m = grid.size(), n = grid[0].size();
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
            grid[r][c] = 0;
            island += to_string(r - i) + to_string(c - j);
            distinct(grid, i, j, r - 1, c, island);
            distinct(grid, i, j, r + 1, c, island);
            distinct(grid, i, j, r, c - 1, island);
            distinct(grid, i, j, r, c + 1, island);
        }
    }
};