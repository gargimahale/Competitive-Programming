#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(K)
// Where K is the max length of the line

class Solution {
public:
	vector<string> removeComments(vector<string>& source) {
		int len = source.size();
		if (len == 0) return {};

		vector <string> ans;
		string build;
		bool block = false;

		for (string line : source) {
			for (int i = 0, m = line.size(); i < m; ++i) {
				string two = line.substr(i, 2);
				if (!block) {
					if (two == "//") break;
					else if (two == "/*") block = true, ++i;
					else build.push_back(line[i]);
				}
				else if (two == "*/") block = false, ++i;
			}

			if (!block && build.size()) ans.push_back(build), build.clear();
		}

		return ans;
	}
}; an