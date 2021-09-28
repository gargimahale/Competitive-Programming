#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// TC: O(n), SC: O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* prev = NULL;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (!temp) {
                if (!q.empty()) {
                    q.push(NULL);
                }
                prev->next = NULL;
                prev = NULL;
            }
            else {
                if (prev) {
                    prev->next = temp;
                }
                prev = temp;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};


// TC: O(n), SC: O(1)

class Solution_1{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        Node *curr = root;
        while (curr)
        {
            Node *ptr = curr;
            while (ptr && ptr->left)
            {
                ptr->left->next = ptr->right;
                if (ptr->next != NULL)
                {
                    ptr->right->next = ptr->next->left;
                }
                else
                    ptr->next = NULL;
                ptr = ptr->next;
            }
            curr = curr->left;
        }
        return root;
    }
};