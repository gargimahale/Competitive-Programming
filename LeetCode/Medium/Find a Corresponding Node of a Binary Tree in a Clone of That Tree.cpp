#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return original == nullptr ? nullptr : (original == target ? cloned : 
        (getTargetCopy(original->left, cloned->left, target) ? : 
        getTargetCopy(original->right, cloned->right, target)));
    }
};