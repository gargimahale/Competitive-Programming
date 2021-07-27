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

    bool dfs(TreeNode* root, int currSum) {
        if (!root) return false;
        bool isLeaf = (root->left == NULL && root->right == NULL);
        int sum = currSum + root->val;
        if (isLeaf) {
            if (sum == targetSum) {
                return true;
            }
        }
        return dfs(root->left, sum) || dfs(root->right, sum);
    }

public:
    int targetSum;
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        return dfs(root, 0);
    }
};