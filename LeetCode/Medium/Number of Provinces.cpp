#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int person) {
        for (int other = 0; other < isConnected.size(); ++other) {
            if (isConnected[person][other] == 1 && !visited[other]) {
                visited[other] = true;
                dfs(isConnected, visited, other);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int cnt = 0;

        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ++cnt;
            } s
        }

        return cnt;
    }
};

// TC: O(n^2)
// SC: O(n)