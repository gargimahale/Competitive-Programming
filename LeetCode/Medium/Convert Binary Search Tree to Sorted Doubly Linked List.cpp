#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// Time: O(N), Space: O(N)
class Solution {
    void dfs(Node* root){
        if (!root){
            return;
        }
        
        dfs(root->left);
        
        if (!head){
            head = root;
        }
        if (prev){
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        dfs(root->right);
    }
public:
    Node* head = nullptr, *prev = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (!root){
            return NULL;
        }
        dfs(root);
        
        // Making the list circular
        prev->right = head;
        head->left = prev;
        return head;
    }
};

