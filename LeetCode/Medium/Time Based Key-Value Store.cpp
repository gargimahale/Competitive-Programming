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
        auto x = upper_bound(begin(map[key]), end(map[key]), pair<int, string>(timestamp, ""), [&](pair<int, string> a, pair<int, string> b) {
            return a.first < b.first;
        });

        return x == map[key].begin() ? "" : prev(x)->second;
    }
};

// OR


// TC: O(logN), SC: O(N)
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key) || mp[key][0].first > timestamp) return "";
        vector<pair<int, string>>& list = mp[key];

        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid].first <= timestamp) left = mid + 1;
            else right = mid - 1;
        }

        return right < 0 ? "" : list[right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

