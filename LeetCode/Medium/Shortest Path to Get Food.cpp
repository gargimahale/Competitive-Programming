#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(vector<vector<char>>& grid, int x, int y) {
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 'X');
    }

    int getFood(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int x = 0, y = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '*') {
                    x = i, y = j;
                    break;
                }
            }
        }

        queue<pair<int, int>> Q;
        Q.push({x, y});
        vector<vector<bool>> visited(row, vector<bool>(col));
        int dist = 0;

        while (!Q.empty()) {
            int len = Q.size();
            for (int i = 0; i < len; ++i) {
                auto pos = Q.front();
                Q.pop();
                if (grid[pos.first][pos.second] == '#') return dist;

                for (auto d : dirs) {
                    int newX = pos.first + d[0];
                    int newY = pos.second + d[1];

                    if (isValid(grid, newX, newY) && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        Q.push({newX, newY});
                    }
                }
            }
            ++dist;

        }

        return -1;
    }
};