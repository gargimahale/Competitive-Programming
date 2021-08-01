#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(const vector<vector<char>>& board, const int& r, const int& c, const char& ch) {
        for (int k = 0; k < 9; ++k) {

            // col
            if (board[k][c] == ch) return false;

            // row
            if (board[r][k] == ch) return false;

            if (board[3 * (r / 3) + k / 3][3 * (c / 3) + k % 3] == ch) return false;
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (backtrack(board)) {
                                return true;
                            }
                            else {
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

