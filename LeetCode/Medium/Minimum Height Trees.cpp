#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        vector<int> curr;
        if (n == 1){
            curr.push_back(0);
            return curr;
        }
        
        // first leaf layer
        for (int i = 0; i < adj.size(); ++i){
            if (adj[i].size() == 1){
                curr.push_back(i);
            }
        }
        
        while(true){
            vector<int> next;
            for (int node: curr){
                for (int neighbor: adj[node]){
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1){
                        next.push_back(neighbor);
                    }
                }
            }
            if (next.empty()){
                return curr;
            }
            curr = next;
        }
    }
};