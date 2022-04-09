#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& matrix, int i, int j, int val){
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= val){
            return 0;
        }
        
        return len[i][j] > 0 ? len[i][j] : len[i][j] = 
            1 + max(
            max(
                dfs(matrix, i - 1, j, matrix[i][j]), 
                dfs(matrix, i + 1, j, matrix[i][j])
            ),
            max(
                dfs(matrix, i, j - 1, matrix[i][j]), 
                dfs(matrix, i, j + 1, matrix[i][j])
            )
        );
    }
    
public:
    vector<vector<int>> len;
    int longestIncreasingPath(vector<vector<int>>& matrix, int res = 0) {
        int r = matrix.size(), c = matrix[0].size();
        len = vector<vector<int>> (r, vector<int> (c));
        
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                res = max(res, dfs(matrix, i, j, matrix[i][j] - 1));
            }
        }
        return res;
    }
};

