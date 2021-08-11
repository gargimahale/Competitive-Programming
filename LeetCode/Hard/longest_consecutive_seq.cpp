#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int best = 0;
        for (int x : nums) {
            if (S.find(x - 1) == S.end()) {
                int y = x + 1;
                while (S.find(y) != S.end()) {
                    y += 1;
                }
                best = max(best, y - x);
            }
        }
        return best;
    }
};