#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& grid, int i, int j, int& sum) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return;

		grid[i][j] = 0;
		++sum;

		dfs(grid, i - 1, j, sum);
		dfs(grid, i + 1, j, sum);
		dfs(grid, i, j - 1, sum);
		dfs(grid, i, j + 1, sum);
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int maxArea = 0, sum = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1) {
					sum = 0;
					dfs(grid, i, j, sum);
					if (sum > maxArea) {
						maxArea = sum;
					}
				}
			}
		}
		return maxArea;
	}
};

// TC: O(R*C)
// SC: O(R*C);