#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(begin(res), end(res), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
                cout << nums[i] << "\n";
            }
            else {
                *it = nums[i];
                cout << "change: " << *it << "\n";
            }
        }

        for (int x : res) cout << x << " ";
        cout << "\n";
        return res.size();
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 1, 0, 3, 2, 3};
    cout << s.lengthOfLIS(a) << "\n";
    return 0;
}