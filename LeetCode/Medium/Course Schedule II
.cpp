#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> deg(numCourses);

        vector<int> ans;

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++deg[p[0]];
        }

        queue<int> Q;

        for (int i = 0; i < numCourses; ++i) {
            if (deg[i] == 0) Q.push(i);
        }

        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            --numCourses;
            ans.push_back(curr);
            for (int ele : adj[curr]) {
                if (--deg[ele] == 0) Q.push(ele);
            }

        }

        return numCourses == 0 ? ans : vector<int>();
    }
};