#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parents;
        unordered_set<string> ancestry;

        for (auto region : regions) {
            int n = region.size();
            for (int i = 1; i < n; ++i) {
                parents[region[i]] = region[0];
            }
        }

        while (!region1.empty()) {
            ancestry.emplace(region1);
            region1 = parents[region1];
        }

        while (!ancestry.count(region2)) {
            region2 = parents[region2];
        }

        return region2;
    }
};