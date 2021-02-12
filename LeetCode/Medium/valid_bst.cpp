#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool checkBST(TreeNode* root, TreeNode* left, TreeNode* right){
        if (!root){
            return true;
        }
        if ((left && left->val>=root->val) || (right && right->val<=root->val)){
            return false;
        }
        return checkBST(root->left, left, root) && checkBST(root->right, root, right);
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, NULL, NULL);
    }
};


// OR

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
// class Solution {
// public:
//     void dfs(TreeNode* root, vector<int>& values){
            // Inorder traversal
//         if (root == nullptr) return;
//         dfs(root->left, values);
//         values.push_back(root->val);
//         dfs(root->right, values);
//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int> values;
//         dfs(root, values);
//         for (int i=1; i<values.size(); ++i){
//             if (values[i] <= values[i-1]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
