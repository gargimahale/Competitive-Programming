#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

/*

Let's consider a constant stream of cache requests with a cache capacity of 3, see below:

A, B, C, A, A, A, A, A, A, A, A, A, A, A, B, C, D
If we just consider a Least Recently Used (LRU) cache with a HashMap + doubly linked list
implementation with O(1) eviction time and O(1) load time, we would have the following elements
cached while processing the caching requests as mentioned above.

[A]
[A, B]
[A, B, C]
[B, C, A] <- a stream of As keeps A at the head of the list.
[C, A, B]
[A, B, C]
[B, C, D] <- here, we evict A, we can do better!
When you look at this example, you can easily see that we can do better - given the higher expected
chance of requesting an A in the future, we should not evict it even if it was least recently used.

A - 12
B - 2
C - 2
D - 1
Least Frequently Used (LFU) cache takes advantage of this information by keeping track of how many
times the cache request has been used in its eviction algorithm.

*/

class LFUCache {
public:

    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    unordered_map<int, int> mostRecentVal, frequency;
    int cap, time = 0;

    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mostRecentVal.find(key) == mostRecentVal.end()) {
            // Element not found
            return -1;
        }
        put(key, mostRecentVal[key]);
        return mostRecentVal[key];
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (mostRecentVal.find(key) == mostRecentVal.end() && mostRecentVal.size() == cap) {
            // Capacity Full
            while (mostRecentVal.size() == cap) {
                // remove elment from map
                auto x = pq.top();
                if (frequency[x.second.second] == x.first) {
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