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
    
    void dfs(TreeNode* root, vector<int>& temp){
        if (root == nullptr) return;
        dfs(root->left, temp);
        temp.push_back(root->val);
        dfs(root->right, temp);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if (!root){
            return 0;
        }
        vector<int> temp;
        dfs(root, temp);
        for (int i=0; i<temp.size(); ++i){
            --k;
            if (k==0){
                return temp[i];
            }
        }
        return -1;
    }
};