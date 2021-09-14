#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1){
            return;
        }
        
        grid[i][j] = -1;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows > 0 ? grid[0].size(): 0;
        
        // first and last row
        for (int i = 0; i<cols; ++i){
            if (grid[0][i] == 1){
                dfs(grid, 0, i);
            }
            
            if (grid[rows-1][i] == 1){
                dfs(grid, rows-1, i);
            }
        }
        
        // first and last col
        for (int i = 0; i < rows; ++i){
            if (grid[i][0] == 1){
                dfs(grid, i, 0);
            }
            
            if (grid[i][cols-1] == 1){
                dfs(grid, i, cols-1);
            }
        }
        
        int res = 0;
        for (int i = 0; i<rows; ++i){
            for (int j = 0; j<cols; ++j){
                res += (grid[i][j] == 1);
            }
        }
        return res;
    }
};