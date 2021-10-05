#include <bits/stdc++.h>
using namespace std;





class LRUCache {
public:
    class Node{
    public:
        int val, key;
        Node* prev, *next;
        Node() {}
        Node(int k, int v): key(k), val(v) {}
    };
    
    Node* head = new Node();
    Node* tail = new Node();
    
    unordered_map<int, Node*> mp;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }
    
    void delNode(Node* newNode){
        Node* delprev = newNode->prev;
        Node* delnext = newNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            int res = resNode->val;
            delNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()){
            if (mp.size() == cap){
                Node* delnode = tail->prev;
                int delKey = delnode->key;
                delNode(delnode);
                mp.erase(delKey);
            }
        }
        else{
            delNode(mp[key]);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
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
