#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Preorder traversal

class Solution {
public:

    TreeNode* prev = NULL;

    void helperFlattenToLL(TreeNode* root) {
        if (!root) return;
        helperFlattenToLL(root->right);
        helperFlattenToLL(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;

    }

    void flatten(TreeNode* root) {
        if (!root) return;
        return helperFlattenToLL(root);
    }
};