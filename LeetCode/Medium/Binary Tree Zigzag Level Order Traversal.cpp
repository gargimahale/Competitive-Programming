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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> res;
        if (!root) return res;

        queue <TreeNode*> nodes;
        nodes.push(root);
        bool check = true;
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();

                int idx = check ? i : (size - 1 - i);
                row[idx] = node->val;
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            check = !check;
            res.push_back(row);
        }
        return res;
    }
};