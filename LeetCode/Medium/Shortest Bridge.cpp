#include <bits/stdc++.h>
using namespace std;


// DFS(Finding the islands) + BFS(shortest path)
class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            return;
        }
        
        grid[i][j] = 2; 
    
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows > 0 ? grid[0].size(): 0;
        bool found = false;
        int lvl = 0;
        
        deque<pair<int, int>> Q;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] == 1 && !found){
                    dfs(grid, i, j);
                    found = true;
                }
                
                if (grid[i][j] == 1 && found){
                    Q.push_back({i, j});
                }
            }
        }
        
        int dir[] = {0, 1, 0, -1, 0};
        
        while(!Q.empty()){
            int size = Q.size();
            for (int i = 0; i < size; ++i){
                auto delta = Q.front();
                Q.pop_front();
                
                for (int i = 0; i < 4; ++i){
                    int x = dir[i] + delta.first;
                    int y = dir[i+1] + delta.second;
                    
                    if (x >= 0 && y >= 0 && x < rows && y < cols){
                        if (grid[x][y] == 2){
                            return lvl;
                        }
                        
                        else if (grid[x][y] == 1){
                            continue;
                        }
                        else if (grid[x][y] == 0){
                            grid[x][y] = 1;
                            Q.push_back({x, y});
                        }
                    }
                }
            }
            ++lvl;
        }
        return 0;
    }
};