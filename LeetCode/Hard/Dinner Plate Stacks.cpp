#include <bits/stdc++.h>
using namespace std;

class DinnerPlates {
public:
    vector<vector<int>> v;
    int cap, l, r, out;

    DinnerPlates(int capacity) {
        v = vector<vector<int>> (200001);
        cap = capacity;
        l = 0, r = 0;
    }

    void push(int val) {
        v[l].push_back(val);
        while (v[l].size() == cap) {
            ++l;
        }

        while (!v[r].empty()) {
            ++r;
        }
        --r;
    }

    int pop() {
        if (v[r].size() == 0 || r < 0) {
            return -1;
        }

        out = v[r].back();
        v[r].pop_back();

        while (v[r].empty() && r > 0) {
            --r;
        }

        if (l > r) {
            l = r;
        }
        return out;
    }

    int popAtStack(int index) {
        if (v[index].size() == 0) {
            return -1;
        }

        int out = v[index].back();
        v[index].pop_back();

        if (l > index) {
            l = index;
        }

        while (v[index].empty() && r == index && r > 0) {
            --r;
        }
        return out;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */