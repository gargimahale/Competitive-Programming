#include <bits/stdc++.h>
#define pb push_back

using namespace std;

// void dfs(vector<vector<int>>& result, int index, vector<int>& nums, vector<int> current){
//     result.pb(current);
//     for (int i = index; i<nums.size(); ++i){
//         current.pb(nums[i]);
//         dfs(result, i+1, nums, current);
//         current.pop_back();
//     }
// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> result;
//     dfs(result, 0, nums, {});
//     return result;
// }


class Solution {
public:

    vector<vector<int>> result;

    void helperSubsets(vector<int>& nums, vector<int> temp, int start, int end) {
        if (start == end) {
            return;
        }

        for (int i = start; i < end; ++i) {
            temp.push_back(nums[i]);
            result.push_back(temp);
            helperSubsets(nums, temp, i + 1, end);
            temp.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        helperSubsets(nums, {}, 0, nums.size());
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};

        int len = nums.size();

        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; ++i) {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }

        return subs;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto list : res) {
        cout << '[';
        for (auto ele : list) {
            cout << ele << "";
        }
        cout << ']' << endl;
    }
    return 0;
}