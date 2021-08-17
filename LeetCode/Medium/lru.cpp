#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity = 0;
    unordered_map<int, pair<int, list<int>::iterator>> log;
    list<int> cache;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (log.find(key) != log.end()){
            // key exists
            cache.erase(log[key].second);
            cache.push_front(key);
            log[key].second = cache.begin();
            return log[key].first;
        }
        // key does not exist
        return -1;
    }
    
    void put(int key, int value) {
        if (log.find(key) == log.end()){
            // key not found
            if (cache.size() == capacity){
                // cap full
                auto last = cache.back();
                cache.pop_back();
                log.erase(last);
            }
        }
        else{
            cache.erase(log[key].second);
        }
        cache.push_front(key);
        log[key] = {value, cache.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
