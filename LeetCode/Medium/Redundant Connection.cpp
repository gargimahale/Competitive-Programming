#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1);
        vector<int> ans;

        for (int i = 1; i <= n; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            int a = edges[i][0];
            int b = edges[i][1];

            while (a != parents[a]) a = parents[a];
            while (b != parents[b]) b = parents[b];

            if (a == b) {
                ans = edges[i];
            } else {
                parents[a] = b;
            }
        }
        return ans;
    }
};