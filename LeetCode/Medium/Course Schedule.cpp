#include <bits/stdc++.h>
using namespace std;

// Topological sort

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);

        // get count for all the indegrees
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++degree[p[0]];
        }

        queue<int> Q;

        // Add to Q the nodes having no dependencies
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) Q.push(i);
        }

        //  ppa
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            --numCourses;
            for (auto next : adj[curr]) {
                if (--degree[next] == 0) Q.push(next);
            }
        }

        return numCourses == 0;
    }
};


// TC: O(|E|+|V|)
// SC: O(|E|+|V|)