#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms){
        stack<int> room;
        room.push(0);
        unordered_set<int> seen = {0};
        while (!room.empty()){
            int i = room.top();
            room.pop();
            for (int r : rooms[i]){
                if (seen.count(r) == 0){
                    room.push(r);
                    seen.insert(r);
                    if (rooms.size() == seen.size())
                        return true;
                }
            }
        }
        return rooms.size() == seen.size();
    }
};