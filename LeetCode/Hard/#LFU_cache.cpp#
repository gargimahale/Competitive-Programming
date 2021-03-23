#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

class LFUCache {
public:

    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    unordered_map<int, int> mostRecentVal;
    unordered_map<int, int> frequency;
    int cap, time = 0;

    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mostRecentVal.find(key) == mostRecentVal.end()){
            // Element not found
            return -1;
        }
        put(key, mostRecentVal[key]);
        return mostRecentVal[key];
    }

    void put(int key, int value) {
        if (cap == 0){
            return;
        }
        if (mostRecentVal.find(key) == mostRecentVal.end() && mostRecentVal.size() == cap){
            // Capacity Full
            while(mostRecentVal.size() == cap){
                // remove elment from map
                auto x = pq.top();
                if (frequency[x.second.second] == x.first){
                    mostRecentVal.erase(x.second.second);
                    frequency.erase(x.second.second);
                }
                pq.pop();
            }
        }
        // Fill Queue and increase time
        mostRecentVal[key] = value;
        frequency[key]++;
        pq.push({frequency[key], {time++, key}});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */