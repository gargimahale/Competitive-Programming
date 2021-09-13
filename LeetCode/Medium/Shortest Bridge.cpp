#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int& m, int& n){
        grid[i][j] = 2;
        if (i-1 >= 0 && grid[i-1][j] == 1) dfs(grid, i-1, j, m, n);
        if (i+1 < m && grid[i+1][j] == 1) dfs(grid, i+1, j, m, n);
        if (j-1 >= 0 && grid[i][j-1] == 1) dfs(grid, i, j-1, m, n);
        if (j+1 < n && grid[i][j+1] == 1) dfs(grid, i, j+1, m, n);
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        bool found = false;
        
        queue<pair<int, int>> Q;
        int lvl = 0;
        
        for (int i = 0; i<rows; ++i){
            for (int j = 0; j<cols; ++j){
                if (grid[i][j] == 1 && !found){
                    dfs(grid, i, j, rows, cols);
                    found = true;
                }
                if (found && grid[i][j] == 1){
                    Q.push({i, j});
                }
            }
        }
        
        int dir[] = {0, 1, 0, -1, 0};
        
        while(!Q.empty()){
            int size = Q.size();
            
            for (int i = 0; i<size; ++i){
                auto pos = Q.front();
                Q.pop();
                
                for (int i = 0; i<4; ++i){
                    int x = pos.first + dir[i];
                    int y = pos.second + dir[i+1];
                    
                    if (x >= 0 && y >= 0 && x < rows && y < cols){
                        if (grid[x][y] == 2){
                            return lvl;
                        }
                        else if (grid[x][y] == 1) continue;
                        else if (grid[x][y] == 0){
                            grid[x][y] = 1;
                            Q.push({x, y});
                        }
                    }
                }
            }
            ++lvl;
        }
        return -1;
    }
};