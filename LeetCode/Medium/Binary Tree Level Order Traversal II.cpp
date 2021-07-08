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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int size = Q.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                auto ele = Q.front();
                Q.pop();
                row[i] = ele->val;
                if (ele->left) Q.push(ele->left);
                if (ele->right) Q.push(ele->right);
            }
            ans.push_back(row);
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};