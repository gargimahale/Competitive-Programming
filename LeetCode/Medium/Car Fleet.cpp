#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> mp;
        for (int i = 0; i < pos.size(); ++i) {
            mp[-pos[i]] = (double)(target - pos[i]) / speed[i];
        }

        double curr = 0;
        int res = 0;

        for (auto x : mp) {
            if (x.second > curr) {
                ++res;
                curr = x.second;
            }
        }
        return res;
    }
};

// TC: O(nlogn)
// SC: O(N)