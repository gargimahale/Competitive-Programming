#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[u]) {
            return false;
        }
        if (u == word.size() - 1) {
            return true;
        }

        bool found = false;
        char temp = board[x][y];

        // mark as visited
        board[x][y] = ' ';

        found = dfs(board, word, u + 1, x, y - 1) || dfs(board, word, u + 1, x, y + 1) || dfs(board, word, u + 1, x + 1, y) ||
                dfs(board, word, u + 1, x - 1, y);

        board[x][y] = temp;
        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size()) return false;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};