#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = maze[0].size(), dir[] = {0, 1, 0, -1, 0};
        queue<vector<int>> Q;
        Q.push(start);
        maze[start[0]][start[1]] = -1;

        while (!Q.empty()) {
            vector<int> p = Q.front();
            Q.pop();

            for (int i = 0; i < 4; ++i) {
                int x = p[0], y = p[1];

                while (x + dir[i] < row && y + dir[i + 1] < col && x + dir[i] >= 0 && y + dir[i + 1] >= 0 && maze[x + dir[i]][y + dir[i + 1]] <= 0) {
                    x += dir[i];
                    y += dir[i + 1];
                }

                if (destination[0] == x && destination[1] == y) return true;

                if (!maze[x][y]) {
                    maze[x][y] = -1;
                    Q.push({x, y});
                }


            }
        }
        return false;
    }
};