#include <bits/stdc++.h>
using namespace std;

// TC: O(N*M)
// SC: O(N+M)

class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;

        board[i][j] = '#';
        dfs(board, i - 1, j, m, n);
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        if (r == 0) return;

        // for first and last column
        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, r, c);
            }
            if (board[i][c - 1] == 'O') {
                dfs(board, i, c - 1, r, c);
            }
        }

        // for first and last row
        for (int j = 0; j < c; ++j) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, r, c);
            }
            if (board[r - 1][j] == 'O') {
                dfs(board, r - 1, j, r, c);
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};