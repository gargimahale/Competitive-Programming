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


// Union Find
class Solution {
public:

    int find(int x, vector<int>& parents) {
        while (x != parents[x]) {
            x = parents[parents[x]];
        }
        return x;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> parents(n);

        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }

        int groups = n;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    int a = find(i, parents);
                    int b = find(j, parents);

                    if (a != b) {
                        parents[a] = b;
                        --groups;
                    }
                }
            }
        }

        return groups;
    }
};


// TC: O(n^3)
// SC: O(n)