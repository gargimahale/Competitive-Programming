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

    vector<TreeNode*> res;
    set<int> S;

    TreeNode* helper(TreeNode* node, bool is_root) {
        if (node == NULL) return NULL;

        bool deleted = S.find(node->val) != S.end();
        if (is_root && !deleted) res.push_back(node);

        node->left = helper(node->left, deleted);
        node->right = helper(node->right, deleted);

        return deleted ? NULL : node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i = 0; i < to_delete.size(); ++i) {
            S.insert(to_delete[i]);
        }

        helper(root, true);
        return res;
    }
};
