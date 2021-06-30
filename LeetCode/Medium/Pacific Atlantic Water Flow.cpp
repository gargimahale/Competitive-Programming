#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        //up
        if (i - 1 >= 0 && visited[i - 1][j] != true && matrix[i - 1][j] >= matrix[i][j])
            dfs(matrix, visited, i - 1, j);
        //down
        if (i + 1 < m && visited[i + 1][j] != true && matrix[i + 1][j] >= matrix[i][j])
            dfs(matrix, visited, i + 1, j);
        //left
        if (j - 1 >= 0 && visited[i][j - 1] != true && matrix[i][j - 1] >= matrix[i][j])
            dfs(matrix, visited, i, j - 1);
        //right
        if (j + 1 < n && visited[i][j + 1] != true && matrix[i][j + 1] >= matrix[i][j])
            dfs(matrix, visited, i, j + 1);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int row = heights.size(), col = heights[0].size();
        if (row == 0 || col == 0) return res;

        vector<vector<bool>> pacific(row, vector<bool>(col));
        vector<vector<bool>> atlantic(row, vector<bool>(col));

        for (int i = 0; i < row; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, col - 1);
        }

        for (int j = 0; j < col; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, row - 1, j);
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
