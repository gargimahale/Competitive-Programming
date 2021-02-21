#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101]={0};
        for (int x: nums){
            cnt[x]++;
        }
        vector<int> ans;
        for (int i=1; i<101; ++i){
            cnt[i] += cnt[i-1];
        }
        
        for (int x: nums){
            if (x == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(cnt[x-1]);
            }
        }
        return ans;
    }
};