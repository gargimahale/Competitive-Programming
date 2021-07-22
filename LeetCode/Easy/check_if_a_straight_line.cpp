#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& coordinates) {
    if (coordinates.size() <= 2) return true;
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    for (int i = 2; i < coordinates.size(); i++) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];
        if ((y2 - y1) * (x1 - x) != (x2 - x1) * (y1 - y)) return false;
    }
    return true;
}

int main(void) {
    vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    cout << solve(coordinates) << "\n";
}