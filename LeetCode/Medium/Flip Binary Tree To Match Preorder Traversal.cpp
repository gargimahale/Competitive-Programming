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
class Solution{
public:
    int i = 0;
    vector<int> result;

    bool dfs(TreeNode *root, vector<int>& voyage){
        if (!root)
            return true;
        if (root->val != voyage[i++])
            return false;
        if (root->left && root->left->val != voyage[i]){
            result.push_back(root->val);
            return dfs(root->right, voyage) && dfs(root->left, voyage);
        }
        return dfs(root->left, voyage) && dfs(root->right, voyage);
    }

    vector<int> flipMatchVoyage(TreeNode *root, vector<int>& voyage){
        return dfs(root, voyage) ? result : vector<int>{-1};
    }
};