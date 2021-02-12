#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res=0;
        sort(nums.begin(), nums.end());
        for (int i=nums.size()-1; i>1; --i){
            cout<<"i:" << i <<"\n";
            int l=0, r=i-1;
            while(l < r){
                if (nums[l]+nums[r] > nums[i]){
                    res+=(r-l);
                    cout << res << "\n";
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return res;
    }
};
