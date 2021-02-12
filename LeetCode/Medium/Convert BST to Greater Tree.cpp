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

// TC, SC: O(n) - recursion stack

class Solution {
public:
    int currSum;
    
    void traverse(TreeNode* root){
        if (root->right){
            traverse(root->right);
        }
        
        currSum += root->val;
        root->val = currSum;
        
        if (root->left){
            traverse(root->left);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root){
            return root;
        }
        currSum = 0;
        traverse(root);
        return root;
    }
};


// OR

// TreeNode* convertBST(TreeNode* root) {
//     if (root){
//         convertBST(root->right);
//         currSum += root->val;
//         root->val = currSum;
//         convertBST(root->left);
//     }
// }