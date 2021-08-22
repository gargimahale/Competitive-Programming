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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (!stk.empty() || curr) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                curr = stk.top(); stk.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};

class Solution {
    void helperInorder(TreeNode* root, vector<int>* ans){
        if (!root){
            return;
        }
        helperInorder(root->left, ans);
        ans->push_back(root->val);
        helperInorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root){
            helperInorder(root, &ans);
        }
        return ans;
    }
};