#include <bits/stdc++.h>

using namespace std;

// Rachit Jain
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return NULL;
        }

        Node* curr = head, *next;

        // create duplicate nodes
        while(curr){
            next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        // setting the random pointers
        curr = head;
        while(curr){
            if ( curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Revert
        curr = head;
        Node* res = head->next;
        while(curr->next && curr->next->next){
            next = curr->next;
            curr->next = curr->next->next;
            next->next = curr->next->next;
            curr = curr->next;
        }

        curr->next = NULL;
        return res;
    }
};