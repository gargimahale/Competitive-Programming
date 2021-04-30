#include <bits/stdc++.h>

using namespace std;

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