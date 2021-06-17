#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = 0;
        for (int x : candies) {
            maxNum = max(maxNum, x);
        }

        vector<bool> res(candies.size(), false);
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxNum) {
                res[i] = true;
            }
        }
        return res;
    }
};