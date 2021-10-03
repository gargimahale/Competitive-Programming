#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> adj;
        vector<int> indegree(numCourses);
        
        for (auto& edge: prerequisites){
            adj[edge[1]].insert(edge[0]);
            indegree[edge[0]]++;
        }
        
        deque<int> Q;
        for (int i = 0; i < numCourses; ++i){
            if (indegree[i] == 0){
                Q.push_back(i);
            }
        }
        
        vector<int> res;
        while(!Q.empty()){
            int ele = Q.front();
            Q.pop_front();
            --numCourses;
            res.push_back(ele);
            for (auto e: adj[ele]){
                if (--indegree[e] == 0){
                    Q.push_back(e);
                }
            }
        }
        return numCourses == 0 ? res: vector<int>{};
    }
};