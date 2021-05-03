#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parents;
    
    int find(int x){
        while (x != parents[x]) {
            parents[x] = parents[parents[x]];  // compression
            x = parents[x];
        }
        return x;
    }
    
    bool unions(int p, int q) {
        int x = find(p);
        int y = find(q);
        if (x != y) {
            parents[x] = y;
            return true;
        }
        return false;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        parents.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        int count = n;
        for (const auto& edge: edges) {
            if (unions(edge[0], edge[1])) {  // changed here
                --count;
            }
        }
        return count;
    }
};