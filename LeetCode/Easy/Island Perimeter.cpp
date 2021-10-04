#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int peri = 0;
        
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j){
                if (grid[i][j] == 0) continue;
                peri += 4;
                if (i > 0) peri -= grid[i-1][j];
                if (i < R-1) peri -= grid[i+1][j];
                if (j > 0) peri -= grid[i][j-1];
                if (j < C-1) peri -= grid[i][j+1];
            }
        }
        return peri;
    }
};