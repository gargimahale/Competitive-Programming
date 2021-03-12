#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, lvl = 0, water = 0;
        while(l<r){
            int lower = height[height[l] < height[r] ? l++:r--];
            lvl = max(lvl, lower);
            water += (lvl-lower);
        }
        return water;
    }
}; 