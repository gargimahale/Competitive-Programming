#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    
    class Node{
    public:
        int key, val;
        Node* prev, *next;
        Node () {}
        Node(int key_, int val_) {
            key = key_;
            val = val_;
        }
    };
    
    Node* head = new Node();
    Node* tail = new Node();
    int cap;
    unordered_map<int, Node*> log;
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        int res = -1;
        if (log.find(key) != log.end()){
            Node* resnode = log[key];
            res = resnode->val;
            deleteNode(resnode);
            log.erase(key);
            addNode(resnode);
            log[key] = head->next;
        }
        return res;
    }
    
    void put(int key, int value) {
        if (log.find(key) == log.end()){
            if (log.size() == cap){
                Node* delNode = tail->prev;
                int delKey = delNode->key;
                deleteNode(delNode);
                log.erase(delKey);
            }
        }
        else{
            deleteNode(log[key]);
            log.erase(key);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        log[key] = newNode;
    }
};


class LRUCache_STL {
public:
    int capacity = 0;
    unordered_map<int, pair<int, list<int>::iterator>> log;
    list<int> cache;
    
    LRUCache_STL(int capacity) {
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
    LRUCache_DLL* lru = new LRUCache_DLL(2);
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
