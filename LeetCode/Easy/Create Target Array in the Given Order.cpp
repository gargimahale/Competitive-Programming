#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> t;
        for (int i = 0; i < index.size(); ++i) {
            t.insert(t.begin() + index[i], nums[i]);
        }

        return t;
    }
};