#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, 
                               {0, -1}, {0, 1}, 
                               {1, -1}, {1, 0}, {1, 1}}; 
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int live = 0;
                for (int k = 0; k < 8; ++k){
                    int x = dir[k][0] + i, y = dir[k][1] + j;
                    if (x < 0 || y < 0 || x >= n || y >= m){
                        continue;
                    }
                    
                    if (board[x][y] & 1){
                        ++live;
                    }
                }
                
                if (board[i][j] == 0){
                    if (live == 3){
                        board[i][j] = 2;
                    }
                }
                else{
                    if (live < 2 || live > 3){
                        board[i][j] = 1;
                    }
                    else{
                        board[i][j] = 3;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                board[i][j] >>= 1;
            }
        }
    }
};