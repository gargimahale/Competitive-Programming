#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node* node = head, *nextNode = head->next;
        while (nextNode != head) {

            if (insertVal == node->val) {
                break;
            }

            if (insertVal > node->val && insertVal < nextNode->val) {
                break;
            }

            if (insertVal > node->val && node->val > nextNode->val) {
                break;
            }

            if (insertVal < nextNode->val && node->val > nextNode->val) {
                break;
            }

            node = node->next;
            nextNode = node->next;
        }
        node->next = new Node(insertVal, nextNode);
        return head;
    }
};

// TC: O(N), SC: O(1)