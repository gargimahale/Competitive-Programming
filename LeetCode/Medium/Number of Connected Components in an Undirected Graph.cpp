#include <bits/stdc++.h>
using namespace std;

// Union find with path compression
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


// DFS
class Solution {
    int dfs(int vertex){
        if (visited[vertex]){
            return 0;
        }
        
        visited[vertex] = true;
        for (int v: adj[vertex]){
            dfs(v);
        }
        return 1;
    }
public:
    unordered_map<int, unordered_set<int>> adj;
    vector<bool> visited;
    
    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<bool> (n);
        for (auto& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        int components = 0;
        for (int v = 0; v < n; ++v){
            components += dfs(v);
        }
        return components;
    }
};