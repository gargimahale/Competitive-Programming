#include <bits/stdc++.h>
using namespace std;


int wiggleMaxLength(vector<int>& nums) {
	int i = 0, j = 1;
	int len = 0;
	while (j < nums.size() && i < j) {
		int sign = j % 2 != 0 ? 1 : -1;
		int diff = nums[j] - nums[j - 1];
		if (sign * diff > 0) {
			len = max(len, j - i + 1);
		}
		else {
			i = j-1;
		}
		++j;
	}
	return len;
}


int main() {
	vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	cout << wiggleMaxLength(nums);
	return 0;
}