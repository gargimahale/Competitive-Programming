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
    int minDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int size = Q.size();
            ++depth;
            for (int i = 0; i < size; ++i) {
                auto ele = Q.front();
                Q.pop();

                if (ele->left) Q.push(ele->left);
                if (ele->right) Q.push(ele->right);

                if (!ele->right && !ele->left) return depth;
            }
        }
        return -1;
    }
};