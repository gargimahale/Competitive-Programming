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
    
    void helperSubsets(vector<int>& nums, vector<int> temp, int start, int end){
        if (start == end){
            return;
        }
        
        for(int i=start; i<end; ++i){
            temp.push_back(nums[i]);
            result.push_back(temp);
            helperSubsets(nums, temp, i+1, end);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        helperSubsets(nums, {}, 0, nums.size());
        return result;
    }
};

// vector<vector<int>> subsets(vector<int>& nums) {
//     int n = nums.size();
//     int p = 1 << n;
//     vector<vector<int>> retVec(p, vector<int>{});
//     for (int i = 1; i<p; ++i){
//         int mask = 0x01;
//         int index = 0;
//         while(i >= mask){
//             if(mask == (i & mask)){
//                 retVec[i].pb(nums[index]);
//             }
//             mask <<= 1;
//             index++;
//         }
//     }
//     return retVec; 
// }

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto list: res){
        cout << '[';
        for (auto ele: list){
            cout << ele << "";
        }
        cout << ']' << endl;
    }
    return 0;
}