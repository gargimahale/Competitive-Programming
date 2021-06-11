#include <bits/stdc++.h>
using namespace std;

// Topological sort

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++degree[p[0]];
        }

        queue<int> Q;

        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) Q.push(i);
        }

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