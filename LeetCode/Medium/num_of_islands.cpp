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
        int r = grid.size(), c = grid[0].size();
        int islands = 0, offset[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    grid[i][j] = 0;
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    while (!Q.empty()) {
                        pair<int, int> p = Q.front(); Q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int row = p.first + offset[k];
                            int col = p.second + offset[k + 1];
                            if (row >= 0 && row < r && col >= 0 && col < c && grid[row][col] == '1') {
                                grid[row][col] = '0';
                                Q.push({row, col});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};