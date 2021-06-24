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
class Solution {
public:
    TreeNode* prev = NULL, *error1 = NULL, *error2 = NULL;

    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }

        inorder(root->left);
        if (prev && root->val < prev->val) {
            if (!error1) {
                error1 = prev;
            }
            if (error1) {
                error2 = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(error1->val, error2->val);
    }
};


// TC: O(N), SC: O(N)