#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int row = rooms.size(), col = rooms[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
        queue<pair<int, int>> canReach;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] == 0) canReach.push({i, j});
            }
        }

        while (!canReach.empty()) {
            auto point = canReach.front();
            canReach.pop();

            int r = point.first, c = point.second;

            for (auto d : dir) {
                int x = r + d[0], y = c + d[1];
                if (x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] <= rooms[r][c] + 1) continue;

                rooms[x][y] = rooms[r][c] + 1;
                canReach.emplace(x, y);
            }
        }

    }
};