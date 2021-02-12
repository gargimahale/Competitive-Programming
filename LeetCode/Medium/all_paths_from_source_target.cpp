#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& temp, int u){
        temp.push_back(u);
        if (u == graph.size()-1){
            result.push_back(temp);
        }
        for (int v: graph[u]){
            dfs(graph, result, temp, v);
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(graph, result, temp, 0);
        return result;
    }
};