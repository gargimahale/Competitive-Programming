#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    
    void travel(Node* root){
        if (root == NULL){
            return;
        }
        
        res.push_back(root->val);
        for (Node* child: root->children){
            travel(child);
        }
    }
    
    vector<int> preorder(Node* root) {
        travel(root);
        return res;
    }
};