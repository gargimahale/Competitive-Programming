#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto x = upper_bound(begin(map[key]), end(map[key]), pair<int, string>(timestamp, ""), [&](pair<int, string> a, pair<int, string> b){
           return a.first < b.first; 
        });
        
        return x == map[key].begin() ? "" : prev(x)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

