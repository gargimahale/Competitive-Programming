#include <bits/stdc++.h>
using namespace std;


int wiggleMaxLength(vector<int> &nums){

	int size = nums.size(), f = 1, d = 1;
	for (int i = 1; i < size; ++i){
		if (nums[i] > nums[i - 1])
			f = d + 1;
		else if (nums[i] < nums[i - 1])
			d = f + 1;
	}
	return min(size, max(f, d));
}

int main() {
	vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	cout << wiggleMaxLength(nums);
	return 0;
}