#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n <= 1) return ans;

        for (int i = 0; i < n; i += 2) {
            ans.insert(ans.end(), nums[i], nums[i + 1]);
        }

        return ans;
    }
};

// TC: O(N), SC: O(N)