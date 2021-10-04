#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node() {}
    Node(int _val): val(_val), next(nullptr){}
    Node(int _val, Node* _next): val(_val), next(_next){}
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head){
            Node* to_insert = new Node(insertVal);
            to_insert->next = to_insert;
            return to_insert;
        }
        
        Node* curr;
        
        for (curr = head; curr->next!= head; curr = curr->next){
            int c = curr->val;
            int n = curr->next->val;
            
            // [max, min]
            if (c > n && (insertVal >= c || insertVal <= n)) break;
            
            // [min, max]
            if (insertVal >= c && insertVal <= n) break;
        }
        
        Node* insertedNode = new Node(insertVal, curr->next);
        curr->next = insertedNode;
        return head;
    }
};

// TC: O(N), SC: O(1)