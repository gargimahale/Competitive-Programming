#include <bits/stdc++.h>
using namespace std;

// 3-Sum

void threeSum(vector<int>& nums, int target) {
    int ans = 1;
    sort(begin(nums), end(nums));
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    ans = nums[i] * nums[j] * nums[k];
                    cout << ans << "\n";
                    return;
                } else if (sum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
    }
}

int main() {
    ifstream myfile("inp.txt");
    int input, target = 2020;
    vector<int> nums;
    while (myfile >> input) {
        nums.push_back(input);
    }
    threeSum(nums, target);
    return 0;
}