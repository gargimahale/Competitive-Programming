#include <bits/stdc++.h>

using namespace std;


// dfs
class Solution {
public:

    void sinkIsland(vector<vector<char>>& grid, int i, int j) {

        // if grid cell is not valid return
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == '0')
            return;

        // sink the current land
        grid[i][j] = '0';

        // sink all adajecent lands
        sinkIsland(grid, i + 1, j); // bottom
        sinkIsland(grid, i - 1, j); // top
        sinkIsland(grid, i, j + 1); // right
        sinkIsland(grid, i, j - 1); // left
    }
    int numIslands(vector<vector<char>>& grid) {

        // holds the number of islands
        int numIslands = 0;


        // sanity check
        // if grid is empty return 0
        if (grid.empty() || grid[0].empty()) return numIslands;


        // get dimensions
        int rows = grid.size();
        int cols = grid[0].size();

        // traverse the whole grid to visit each land
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // if land is found, count it as 1 island (i.e. increment numIslands)
                // then sink the entire island through DFS
                // so that the part of it is not recounted
                if (grid[i][j] == '1') {
                    numIslands++;
                    // sink the land and all adjacent land(s) of this island
                    sinkIsland(grid, i, j);
                }
            }
        }
        // return result
        return numIslands;
    }
};


//bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        deque<pair<int, int>> canReach;
        vector<int> dir = {0, 1, 0, -1, 0};
        int numIslands = 0, rows = grid.size(), cols = grid[0].size();
        
        for (int i = 0; i<rows; ++i){
            for (int j = 0; j<cols; ++j){
                if (grid[i][j] == '1'){
                    ++numIslands;
                    
                    grid[i][j] = '0';
                    canReach.push_back({i, j});
                    while(!canReach.empty()){
                        auto current = canReach.front();
                        canReach.pop_front();
                        
                        int r = current.first, c = current.second;
                        for (int i = 0; i < 4; ++i){
                            int new_row = r + dir[i], new_col = c + dir[i+1];
                            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && grid[new_row][new_col] == '1'){
                                canReach.push_back({new_row, new_col});
                                grid[new_row][new_col] = '0';
                            }
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};