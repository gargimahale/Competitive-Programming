#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> data;
    int curr_snap;

    SnapshotArray(int length) {
        data.resize(length);
        curr_snap = 0;
    }

    void set(int index, int val) {
        if (data[index].empty() || data[index].back().first != curr_snap)
            data[index].push_back({curr_snap, val});
        else {
            data[index].back().second = val;
        }
    }

    int snap() {
        return curr_snap++;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(begin(data[index]), end(data[index]), pair<int, int>(snap_id, INT_MAX));
        return it == data[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */