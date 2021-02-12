#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:

    int capacity;
    list<int> cache;
    unordered_map<int, pair<list<int>::iterator, int>> mp;


    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()){
            cache.erase(mp[key].first);
            cache.push_front(key);
            mp[key].first = cache.begin();
            return mp[key].second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()){
            if (cache.size() == capacity){
                // evict
                int last_key = cache.back();
                cache.pop_back();
                mp.erase(last_key);
            }
        }
        else{
            cache.erase(mp[key].first);
        }
        cache.push_front(key);
        mp[key] = {cache.begin(), value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
