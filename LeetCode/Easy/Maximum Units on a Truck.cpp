#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(begin(boxTypes), end(boxTypes), [&](auto a, auto b) {
            return a[1] > b[1];
        });

        int ans = 0;
        for (auto box : boxTypes) {
            int x = min(box[0], truckSize);
            ans += (x * box[1]);
            truckSize -= x;
            if (!truckSize) break;
        }
        return ans;
    }
};

// TC: O(nlogn)
// SC: O(1)