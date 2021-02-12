#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int minExtra = INT_MAX;
        for (auto nut: nuts){
            int nut2tree = abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]);
            int nut2squirrel = abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]);
            sum += nut2tree;
            minExtra = min(minExtra, nut2squirrel - nut2tree);
        }
        return 2* sum + minExtra;
    }
};