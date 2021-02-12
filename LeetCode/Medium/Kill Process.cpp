#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> killed;
        unordered_map<int, vector<int>> mp;
        
        for (int i=0; i<pid.size(); ++i){
            mp[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> q;
        q.push(kill);
        
        while(!q.empty()){
            killed.push_back(q.front());
            q.pop();
            for (int x: mp[killed.back()]){
                q.push(x);
            }
        }
        return killed;
        
    }
};