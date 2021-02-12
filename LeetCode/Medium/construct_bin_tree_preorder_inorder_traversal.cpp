#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop, int& inPos, int& prePos){
        if (prePos >= preorder.size()){
            return nullptr;
        }

        if (inorder[inPos] == stop){
            inPos++;
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prePos]);
        prePos++;
        root->left = build(preorder, inorder,  root->val, inPos, prePos);
        root->right = build(preorder, inorder,  stop, inPos, prePos);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inPos = 0, prePos = 0;
        return build(preorder, inorder, INT_MIN, inPos, prePos);
    }
};
