#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        for (int i = 1; i<nums.size()-1; ++i){
            int avg = (nums[i-1] + nums[i+1])/2;
            if (avg == nums[i]){
                swap(nums[i], nums[i+1]);
            }
        }
        
        for (int i = nums.size()-2; i > 0; --i){
            int avg = (nums[i-1] + nums[i+1])/2;
            if (avg == nums[i]){
                swap(nums[i], nums[i-1]);
            }
        }
        return nums;
    }
};

int32_t main(){
	Solution S;
	vector<int> nums = {1, 2, 3, 4, 5};
	S.rearrangeArray(nums);
	for (int x: nums) cout << x << " ";
	cout << "\n";
	return 0;
}