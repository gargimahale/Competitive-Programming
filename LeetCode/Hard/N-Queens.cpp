#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;
    bool isSafe(const vector<string>& board, int row, int col) {
        // column check
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][col] == 'Q')
                return false;
        }

        int x = row, y = col;

        // left diagonal
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            --x, --y;
        }

        // right diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            --row, ++col;
        }

        // safe
        return true;
    }

    void placeQueen(vector<string>& board, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); ++col) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                placeQueen(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(const int& n) {
        if (n == 0) return ans;
        vector<string> board(n, string(n, '.'));
        placeQueen(board, 0);
        return ans;
    }
};
