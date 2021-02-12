#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string word: words){
            mp[word]++;
        }
        
        vector<pair<int, string>>vec;
        
        for (auto it = mp.begin(); it!=mp.end(); ++it){
            vec.push_back(make_pair(it->second, it->first));
        }
        sort(vec.begin(), vec.end(), [](pair<int, string>& a, pair<int, string>& b){
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        
        vector<string> res;
        for (auto& pi: vec){
            if (k==0) break;
            res.push_back(pi.second);
            k--;
        }
        return res;
        
    }
};