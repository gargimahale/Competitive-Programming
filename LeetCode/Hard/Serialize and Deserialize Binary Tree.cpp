#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        istringstream ss(data);
        return helperDeserialize(ss);
    }
    
    TreeNode* helperDeserialize(istringstream& ss){
        string str;
        getline(ss, str, ',');
        if (str == "#") return NULL;
        else{
            TreeNode* root = new TreeNode(stoi(str));
            root->left = helperDeserialize(ss);
            root->right = helperDeserialize(ss);
            return root;
        }
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));