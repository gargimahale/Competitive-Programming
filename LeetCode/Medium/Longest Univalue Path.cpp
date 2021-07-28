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

    int longest_path = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = root->left ? dfs(root->left) : 0;
        int right = root->right ? dfs(root->right) : 0;

        int res_l = root->left && root->left->val == root->val ? left + 1 : 0;
        int res_r = root->right && root->right->val == root->val ? right + 1 : 0;

        longest_path = max(longest_path, res_l + res_r);
        return max(res_l, res_r);
    }

    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        longest_path = 0;
        dfs(root);
        return longest_path;
    }
};