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
    int checkIfBalanced(TreeNode* root, bool& check) const {
        if (!root || !check) return check;

        int left = checkIfBalanced(root->left, check);
        int right = checkIfBalanced(root->right, check);

        if (abs(left - right) > 1) {
            check = false;
            return 0;
        }

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool check = true;
        checkIfBalanced(root, check);
        return check;
    }
};