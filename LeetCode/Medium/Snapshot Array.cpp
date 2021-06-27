#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:

    int curr_snap = 0;
    unordered_map<int, vector<pair<int, int>>> mp;

    SnapshotArray(int length) {}

    void set(int index, int val) {
        if (mp[index].empty() || mp[index].back().first != curr_snap) {
            mp[index].push_back({curr_snap, val});
        }
        else {
            mp[index].back().second = val;
        }
    }

    int snap() {
        return curr_snap++;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(begin(mp[index]), end(mp[index]), pair<int, int>(snap_id, INT_MAX));
        return it == mp[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
