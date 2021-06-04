#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int areaOfLand(vector<vector<int>>& grid, int i, int j) {
		if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
			grid[i][j] = 0;
			return 1 + areaOfLand(grid, i + 1, j) + areaOfLand(grid, i - 1, j) + areaOfLand(grid, i, j - 1) + areaOfLand(grid, i, j + 1);
		}
		return 0;
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					ans = max(ans, areaOfLand(grid, i, j));
				}
			}
		}
		return ans;
	}
};