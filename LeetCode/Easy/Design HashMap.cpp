#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> map;

    MyHashMap() {
        map.resize(100001, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        map[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return map[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<vector<pair<int, int>>> map;
    const int size = 10000;
    MyHashMap() {
        map.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % size;
        vector<pair<int, int>>& row = map[index];
        
        for (auto it = row.begin(); it != row.end(); ++it){
            if (it->first == key){
                it->second = value;
                return;
            }
        }
        row.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % size;
        vector<pair<int, int>>& row = map[index];
        
        for (auto it = row.begin(); it != row.end(); ++it){
            if (it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % size;
        vector<pair<int, int>>& row = map[index];
        
        for (auto it = row.begin(); it != row.end(); ++it){
            if (it->first == key){
                row.erase(it);
                return;
            }
        }
    }
};