#include <bits/stdc++.h>

using namespace std;

class LogSystem {
public:
    
    multimap<string, int> map;
    
    LogSystem() {}
    
    void put(int id, string timestamp) {
        map.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        if (gra == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if (gra == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if (gra == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if (gra == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if (gra == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        
        vector<int> ans;
        auto start = map.lower_bound(s);
        auto end = map.upper_bound(e);
        
        for (auto it = start; it!=end; ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */