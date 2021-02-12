#include<bits/stdc++.h>

using namespace std;
#define pb push_back

vector<vector<int>> res;

void dfs(vector<int>& nums, vector<int>& temp, int idx, int n){
    if (idx == n){
        return;
    }
    for (int i=idx; i<n; ++i){
        if(i != idx && nums[i] == nums[i-1]){
            continue;
        }
        temp.pb(nums[i]);
        res.pb(temp);
        dfs(nums, temp, i+1, n);
        temp.pop_back();

    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    res.pb({});
    vector<int> temp;
    dfs(nums, {}, 0, nums.size());
    return res;
}

int main(){
    vector<int> nums = {1, 2, 3, 2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for (auto list: res){
        cout << '[';
        for (auto ele: list){
            cout << ele << "";
        }
        cout << ']' << endl;
    }
    return 0;
}