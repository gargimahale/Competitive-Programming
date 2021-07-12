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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<pair<TreeNode*, int>> S;
        S.push({root, 0});

        while (!S.empty()) {
            auto t = S.top();
            S.pop();
            TreeNode* curr = t.first;
            int state = t.second;

            if (!curr or state == 3) continue;

            S.push({curr, state + 1});

            if (state == 0) S.push({curr->left, 0});
            else if (state == 1) ans.push_back(curr->val);
            else if (state == 2) S.push({curr->right, 0});
        }

        return ans;
    }
};

// Improvement on this is Morris Traversal