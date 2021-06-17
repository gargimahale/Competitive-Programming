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
    TreeNode* invertTree(TreeNode* root) {

        // Recursive Solution
        // if (root){
        //     invertTree(root->left);
        //     invertTree(root->right);
        //     swap(root->left, root->right);
        // }
        // return root;

        // Iterative Solutions
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* p = stk.top(); stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }
};
