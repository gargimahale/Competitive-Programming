#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());

		// base case
		if (n < 3) return ans;

		for (int i = 0; i < nums.size() - 2; ++i) {
			// ignores duplicates
			if (i == 0 || nums[i] != nums[i - 1]) {
				int j = i + 1, k = nums.size() - 1;
				while (j < k) {
					int sum = nums[i] + nums[j] + nums[k];
					if (sum == 0) {
						ans.push_back({nums[i], nums[j], nums[k]});

						// ignores dupliactes
						while (j < k && nums[j] == nums[j + 1]) ++j;
						while (j < 0 && nums[k] == nums[k - 1]) --k;
						++j, --k;
					}
					else if (sum > 0) --k;
					else ++j;
				}
			}
		}
		return ans;
	}
};