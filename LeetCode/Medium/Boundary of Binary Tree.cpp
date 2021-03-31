#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)

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
class Solution
{
public:
    vector<int> bounds;

    void getBounds(TreeNode *node, bool lb, bool rb)
    {
        if (!node)
            return;

        if (lb)
            bounds.push_back(node->val);
        if (!lb && !rb && !node->left && !node->right)
        {
            bounds.push_back(node->val);
        }

        getBounds(node->left, lb, rb && !node->right);
        getBounds(node->right, lb && !node->left, rb);

        if (rb)
        {
            bounds.push_back(node->val);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return bounds;

        if (root)
        {
            bounds.push_back(root->val);
            getBounds(root->left, true, false);
            getBounds(root->right, false, true);
        }

        return bounds;
    }
};
