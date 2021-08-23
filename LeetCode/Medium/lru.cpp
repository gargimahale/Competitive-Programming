#include <list>
#include <unordered_map>
#include <iostream>

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

int32_t main(){
    LRUCache* lru = new LRUCache(2);
    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << "\n";
    lru->put(3, 3);
    cout << lru->get(2) << "\n";
    lru->put(4, 4);
    cout << lru->get(1) << "\n";
    cout << lru->get(3) << "\n";
    cout << lru->get(4) << "\n";
}
