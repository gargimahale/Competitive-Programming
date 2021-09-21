#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int curr, int col){
        if (color[curr] != 0){
            return color[curr] == col;
        }
        
        color[curr] = col;
        for (auto next: adj[curr]){
            if (!dfs(next, -col)){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> color;
    vector<vector<int>> adj;
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj = vector<vector<int>> (n+1, vector<int>());
        for (auto edge: dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        color = vector<int> (n+1, 0);
        
        for (int i = 1; i<= n; ++i){
            if (color[i] == 0 && !dfs(i, 1)){
                return false;
            }
        }
        return true;
    }
};