#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		if (costs.size() == 0) return 0;
		int n = costs.size(), r = 0, g = 0, b = 0;
		for (int i = 0; i < n; ++i) {
			int rr = r, bb = b, gg = g;
			r = costs[i][0] + min(bb, gg);
			b = costs[i][1] + min(rr, gg);
			g = costs[i][2] + min(rr, bb);
		}
		return min({r, g, b});
	}
};


// TC: O(N), SC: O(1)