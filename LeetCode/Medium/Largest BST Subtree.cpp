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

    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        if (left[1] < root->val && root->val < right[0]) {
            return {min(left[0], root->val), max(root->val, right[1]), left[2] + right[2] + 1};
        }
        return {INT_MIN, INT_MAX, max(left[2], right[2])};

    }

    int largestBSTSubtree(TreeNode* root) {
        vector<int> ret = dfs(root);
        return ret[2];
    }
};
