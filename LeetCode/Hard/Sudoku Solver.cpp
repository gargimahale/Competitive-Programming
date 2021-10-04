#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(vector<vector<char>>& board, int i, int j, char ch){
        for (int k = 0; k < 9; ++k){
            if (board[k][j] == ch || board[i][k] == ch) return false;
            if (board[3*(i/3)+k/3][3*(j/3)+k%3] == ch) return false;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board){
        int R = board.size(), C = board[0].size();
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j){
                if (board[i][j] == '.'){
                    for (char ch = '1'; ch <= '9'; ++ch){
                        if (isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if (backtrack(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};