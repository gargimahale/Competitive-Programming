#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0, j = h.size()-1;
        int water = 0;
        while(i < j){
            int temp = min(h[i], h[j]);
            water = max(water, (j-i)*temp);
            while(h[i] <= temp && i < j) ++i;
            while(h[j] <= temp && i < j) --j;
        }
        return water;
    }
};