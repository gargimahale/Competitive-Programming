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

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left_cnt = dfs(root->left);
        int right_cnt = dfs(root->right);
        int total = left_cnt + right_cnt;

        if (S.count(root->val)) {
            ++total;
        }

        if (total == S.size() && !res) {
            res = root;
        }

        return total;
    }

public:

    TreeNode* res = nullptr;
    unordered_set<int> S;

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for (auto& node : nodes) S.emplace(node->val);
        dfs(root);
        return res;
    }
};