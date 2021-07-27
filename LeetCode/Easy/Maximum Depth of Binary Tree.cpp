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
    int maxDepth(TreeNode* root) {
        if (root)
            return 1 + max(maxDepth(root->left),  maxDepth(root->right));
        return 0;
    }
};

// TC: O(n), SC: O(n)


class Solution {
public:
    int maxDepth(TreeNode* root) {
        int height = 0;
        if (!root) return height;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int n = Q.size();
            ++height;
            for (int i = 0; i < n; ++i) {
                auto curr = Q.front(); Q.pop();

                if (curr->left) {
                    Q.push(curr->left);
                }

                if (curr->right) {
                    Q.push(curr->right);
                }
            }
        }
        return height;
    }
};

// TC: O(N), SC: O(N)