#include <bits/stdc++.h>
using namespace std;

class Solution {

    int find(int x, vector<int>& parents) {
        while (x != parents[x]) {
            x = parents[parents[x]];
        }
        return x;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        if (e != n - 1) return false;

        vector<int> parents(n);
        for (int i = 0; i < n; ++i) parents[i] = i;

        for (int i = 0; i < e; ++i) {
            int a = find(edges[i][0], parents);
            int b = find(edges[i][1], parents);
            if (a == b) return false;

            parents[b] = a;
        }

        return true;
    }
};