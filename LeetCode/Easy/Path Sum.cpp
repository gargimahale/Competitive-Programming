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

    bool hasPathSum(TreeNode* root, const int& targetSum, int currSum) {
        if (!root) return false;
        int sum = currSum + root->val;
        bool isLeaf = !root->left && !root->right;

        if (isLeaf && sum == targetSum) {
            return true;
        }
        return hasPathSum(root->left, targetSum, sum) || hasPathSum(root->right, targetSum, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root, targetSum, 0);
    }
};