#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int count = 0;

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        if (root == p || root == q) {
            ++count;
            return root;
        }

        return !left ? right : !right ? left : root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = dfs(root, p, q);
        return count == 2 ? result : NULL;
    }
};