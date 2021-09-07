#include <bits/stdc++.h>
using namespace std;


// Time: O(N*S), Space: O(N)
class Solution {
    string shift(string& s){
        string t;
        for (int i = 1; i<s.size(); ++i){
            int diff = s[i] - s[i-1];
            if (diff < 0){
                diff += 26;
            }
            t += 'a' + diff + ',';
        }
        return t;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        
        int n = strings.size();
        if (!n){
            return {};
        }
        
        vector<vector<string>> groups;
        for (string& str: strings){
            mp[shift(str)].push_back(str);
        }
        
        for (auto it: mp){
            vector<string> group = it.second;
            sort(begin(group), end(group));
            groups.push_back(it.second);
        }
        return groups;
    }
};