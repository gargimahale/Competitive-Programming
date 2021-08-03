#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(const vector<vector<int>>& rooms) {
        unordered_set<int> S;
        queue<int> Q;
        Q.emplace(0);
        S.emplace(0);

        while (!Q.empty()) {
            int no = Q.front(); Q.pop();
            for (const int& key : rooms[no]) {
                if (!S.count(key)) {
                    S.emplace(key);
                    Q.emplace(key);
                }
            }
        }
        return S.size() == rooms.size();
    }
};