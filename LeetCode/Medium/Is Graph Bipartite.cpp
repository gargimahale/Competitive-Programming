#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        queue<int> q;
        
        for (int i=0; i<n; ++i){
            if (color[i]){
                continue;   // graph node previously coloured
            }
            
            color[i] = 1;
            for(q.push(i); !q.empty(); q.pop()){
                int currNode = q.front();
                for (int neighbour: graph[currNode]){
                    if (!color[neighbour]){
                        color[neighbour] = -color[currNode];
                        q.push(neighbour);
                    }
                    else if (color[neighbour] == color[currNode]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
