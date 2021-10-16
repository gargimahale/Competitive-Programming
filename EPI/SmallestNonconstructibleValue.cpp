#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int SmallestNonconstructibleValue(vector<int>& nums){
		sort(begin(nums), end(nums));
		int max_constructible_value = 0;
		for (int ele: nums){
			if(ele > max_constructible_value+1){
				return max_constructible_value + 1;
			}
			max_constructible_value += ele;
		}
		return -1;
	}
};

int main(void){
	Solution sol;
	vector<int> nums = {12, 2, 1, 15, 2, 4};
	cout << sol.SmallestNonconstructibleValue(nums) << "\n";
}