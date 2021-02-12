#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int lo=0, hi = nums.size();
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if (nums[mid]-mid-k>=nums[0]){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return nums[0]+lo+k-1;
    }
};