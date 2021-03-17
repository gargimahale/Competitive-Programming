#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl
#define int long long
const int N = 1e5 + 5;

class Solution {
public:

	double rad, x, y;

	Solution(double radius, double x_center, double y_center) {
		rad = radius;
		x = x_center;
		y = y_center;
	}

	vector<double> randPoint() {
		double x1, y1;
		do {
			x1 = (2 * ((double) rand() / RAND_MAX) - 1.0) * rad;
			y1 = (2 * ((double) rand() / RAND_MAX) - 1.0) * rad;
		} while (x1 * x1 + y1 * y1 > rad * rad);
		return {x1 + x, y1 + y};
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */