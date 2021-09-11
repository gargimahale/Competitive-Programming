#include <bits/stdc++.h>
using namespace std;

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

class Codec {
    void encode_dfs(Node* root, string* s){
        if (!root){
            return;
        }
        (*s) += " " + to_string(root->val) + " " + to_string(root->children.size());
        for (auto child: root->children) encode_dfs(child, s);
    }
    
    Node* decode_dfs(istringstream* iss){
        int val, child_size;
        if ((*iss) >> val >> child_size){
            Node* root = new Node(val);
            for (int i = 0; i<child_size; ++i){
                root->children.push_back(decode_dfs(iss));
            }
            return root;
        }
        return nullptr;
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        encode_dfs(root, &s);
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return decode_dfs(&iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));