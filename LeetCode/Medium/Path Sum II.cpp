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
    void findPaths(TreeNode *root, vector<vector<int>> &paths, int sum, vector<int> &path)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
        {
            paths.push_back(path);
        }
        findPaths(root->left, paths, sum - root->val, path);
        findPaths(root->right, paths, sum - root->val, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> paths;
        vector<int> path;
        if (root == nullptr)
            return paths;

        findPaths(root, paths, sum, path);
        return paths;
    }
};