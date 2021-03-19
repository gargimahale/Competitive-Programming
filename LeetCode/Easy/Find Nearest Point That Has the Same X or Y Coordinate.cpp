#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points){
        int dist = INT_MAX, idx = -1;
        bool check = false;
        for (int i = 0; i < points.size(); ++i){
            if (points[i][0] == x || points[i][1] == y){
                int val = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (val < dist){
                    dist = val;
                    idx = i;
                }
            }
        }
        return idx;
    }
};