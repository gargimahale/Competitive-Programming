#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int smallestCommonElement(vector<vector<int>>& mat) {
		unordered_map<int, int> mp;
		for (auto x : mat) {
			for (int ele : x) {
				mp[ele]++;
			}
		}

		int minVal = INT_MAX;
		for (auto x : mp) {
			if (x.second == mat.size()) {
				minVal = min(x.first, minVal);
			}
		}

		return minVal == INT_MAX ? -1: minVal;
	}
};
