#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int aster : asteroids) {
            bool destroyed = false;
            while (res.size() && res.back() > 0 && aster < 0 && !destroyed) {
                if (res.back() >= -aster) {
                    destroyed = true;
                }
                if (res.back() <= -aster) {
                    res.pop_back();
                }
            }
            if (!destroyed)
                res.push_back(aster);
        }

        return res;
    }
};

// TC: O(N)
// SC: O(N)