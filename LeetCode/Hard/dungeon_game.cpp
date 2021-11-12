#include <vector>
#include <iostream>

using namespace std;

int solve(vector <vector <int>>& dungeon) {
    int r = dungeon.size(), c = dungeon[0].size();
    
    vector<vector<int>> sol (r, vector<int>(c));

    sol[r - 1][c - 1] = dungeon[r - 1][c - 1] > 0 ? 1 : 1 - dungeon[r - 1][c - 1];

    // for last column
    for (int i = r - 2; i >= 0; --i)
        sol[i][c - 1] = max(sol[i + 1][c - 1] - dungeon[i][c - 1], 1);

    // for last row
    for (int j = c - 2; j >= 0; --j)
        sol[r - 1][j] = max(sol[r - 1][j + 1] - dungeon[r - 1][j], 1);

    for (int i = r - 2; i >= 0; --i)
        for (int j = c - 2; j >= 0; --j)
            sol[i][j] = max(min(sol[i + 1][j], sol[i][j + 1]) - dungeon[i][j], 1);

    return sol[0][0];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int>> dungeon = {{ -2, -3, 3}, { -5, -10, 1}, {10, 30, -5}};
    int t = 1;
    while (t--) {
        cout << solve(dungeon);
    }
    return 0;
}