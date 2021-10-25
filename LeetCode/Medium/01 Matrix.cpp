#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        const vector<int> dir = {0, 1, 0, -1, 0};
        
        deque<pair<int, int>> Q;
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j){
                if (mat[i][j] == 0){
                    Q.push_back({i, j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        
        while(!Q.empty()){
            auto current = Q.front();
            Q.pop_front();
            
            for (int i = 0; i < 4; ++i){
                int x = current.first + dir[i];
                int y = current.second + dir[i+1];
                
                if (x < 0 || x >= R || y < 0 || y >= C || mat[x][y] != -1){
                    continue;
                }
                
                mat[x][y] = mat[current.first][current.second] + 1;
                Q.push_back({x, y});
            }
        }
        return mat;
    }
};