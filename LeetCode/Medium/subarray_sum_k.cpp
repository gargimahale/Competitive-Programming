#include <bits/stdc++.h>

using namespace std;

// Prefix Sum logic - Errichto

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, pref = 0;
        unordered_map<int, int> cntPref;
        cntPref[pref]++;
        for (int i = 0; i < n; ++i) {
            pref += nums[i];
            int need = pref - k;
            ans += cntPref[need];
            cntPref[pref]++;
        }
        return ans;
    }
};