#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;

        for (int i = 0; i < routes.size(); ++i) {
            for (int& r : routes[i]) {
                to_routes[r].push_back(i);
            }
        }

        queue<pair<int, int>> Q;
        Q.push({source, 0});
        unordered_set<int> seen = {source};

        while (!Q.empty()) {
            int stop = Q.front().first, bus = Q.front().second; Q.pop();

            if (stop == target) {
                return bus;
            }

            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        Q.push({j, bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};