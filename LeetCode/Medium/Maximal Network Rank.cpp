#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        vector<unordered_set<int>> adj(n);
        
        for(auto& road: roads){
            cnt[road[0]]++;
            cnt[road[1]]++;
            
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        
        for (int i = 0; i<n-1; ++i){
            for (int j = i+1; j < n; ++j){
                int temp = cnt[i] + cnt[j] - (adj[i].count(j) == 1 ? 1: 0);
                
                maximal = max(maximal, temp);
            }
        }
        return maximal;
    }
};