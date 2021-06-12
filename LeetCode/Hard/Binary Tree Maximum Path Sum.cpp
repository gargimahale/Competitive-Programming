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
    int maxSum = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);

        int new_price = root->val + left + right;
        maxSum = max(maxSum, new_price);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};

// TC: O(N)
// SC: O(H)