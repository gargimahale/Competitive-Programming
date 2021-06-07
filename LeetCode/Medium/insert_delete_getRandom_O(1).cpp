#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    // set<int> arr;
    unordered_map<int, int> map;
    vector<int> list;
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        list.push_back(val);
//         Storing the idx
        map[val] = list.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) != map.end()) {
            int idx = map[val];
            map[list[list.size() - 1]] = idx;
            map.erase(val);
            swap(list[idx], list[list.size() - 1]);
            list.pop_back();
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
