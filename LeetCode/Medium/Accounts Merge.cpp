#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN), SC: O(N)

class Solution {
    int findParents(int x, vector<int>& parents){
        int id = x;
        
        // To get the root - path compression
        while(id != parents[id]) {
            id = parents[id];
        }
        
        while(x != parents[x]){
            int temp = parents[x];
            parents[x] = id;
            x = temp;
        }
        return x;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int n = accounts.size();
        if (n == 0){
            return {};
        }
        
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        vector<int> parents(n, 0);
        
        for (int i = 0; i<n; ++i){
            parents[i] = i;
            
            for (int j = 1; j<accounts[i].size(); ++j){
                if (mp.find(accounts[i][j]) != mp.end()){
                    int a = findParents(i, parents);
                    int b = findParents(mp[accounts[i][j]], parents);
                    
                    if (a != b){
                        parents[a] = b;
                    }
                }else{
                    mp[accounts[i][j]] = parents[i];
                }
            }
        }
        
        unordered_map<int, vector<string>> res_mp;
        
        for (auto ele: mp){
            int idx = findParents(ele.second, parents);
            res_mp[parents[ele.second]].push_back(ele.first);
        }
        
        for (auto vec: res_mp){
            vector<string> emails = vec.second;
            sort(begin(emails), end(emails));
            emails.insert(begin(emails), accounts[vec.first][0]);
            res.push_back(emails);
        }
        return res;
    }
};