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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        if (!root->left && !root->right) return sum * 10 + root->val;
        return pathSum(root->left, sum * 10 + root->val) + pathSum(root->right, sum * 10 + root->val);

    }

public:
    int sumNumbers(TreeNode* root) {
        return pathSum(root, 0);
    }
};
