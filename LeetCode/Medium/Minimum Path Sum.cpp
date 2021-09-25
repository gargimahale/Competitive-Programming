#include <bits/stdc++.h>
using namespace std;


// Time: O(N*M), Space: O(N*M)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows > 0 ? grid[0].size(): 0;
        
        vector<vector<int>> dp(rows, vector<int> (cols, grid[0][0]));
        for (int i = 1; i < cols; ++i){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for (int j = 1; j < rows; ++j){
            dp[j][0] = dp[j-1][0] + grid[j][0];
        }
        
        for (int i = 1; i<rows; ++i){
            for (int j = 1; j<cols; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};


// Time: O(N*M), Space: O(1)
class Solution_1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows > 0 ? grid[0].size(): 0;
        for (int i = 1; i < cols; ++i){
            grid[0][i] += grid[0][i-1];
        }
        
        for (int j = 1; j < rows; ++j){
            grid[j][0] += grid[j-1][0];
        }
        
        for (int i = 1; i<rows; ++i){
            for (int j = 1; j<cols; ++j){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[rows-1][cols-1];
    }
};
