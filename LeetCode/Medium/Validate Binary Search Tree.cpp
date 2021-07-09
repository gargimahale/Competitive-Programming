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

    bool isValidBST(TreeNode* node, long lower_limit, long upper_limit) {
        if (!node) return true;
        if (node->val <= lower_limit || node->val >= upper_limit) return false;
        return isValidBST(node->left, lower_limit, node->val) && isValidBST(node->right, node->val, upper_limit);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

// BFS

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        queue<pair<TreeNode*, pair<long, long>>> Q;
        Q.push({root, {LONG_MIN, LONG_MAX}});

        while (!Q.empty()) {
            auto ele = Q.front();
            Q.pop();

            if (ele.first->val <= ele.second.first || ele.first->val >= ele.second.second) return false;

            if (ele.first->left) {
                Q.push({ele.first->left, {ele.second.first, ele.first->val}});
            }
            if (ele.first->right) {
                Q.push({ele.first->right, {ele.first->val, ele.second.second}});
            }
        }

        return true;
    }
};