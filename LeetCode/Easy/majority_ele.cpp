#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int solve(vector<int>& nums){
    int n = nums.size();
    unordered_map<int, int> weird;
    int val = floor(n/2);
    for (auto i = nums.begin(); i != nums.end(); ++i) weird[*i]++;
    for (auto& it : weird){
        if (it.second > val)
            return it.first;
    }
    return 0;

}

int main(int argc, char** argv){
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> k;
        nums.push_back(k);
    }
    cout << solve(nums);
    return 0;
}