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
class BSTIterator {

    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            arr.emplace_back(root->val);
            dfs(root->right);
        }
    }

public:
    vector<int> arr;
    int i = 0;
    BSTIterator(TreeNode* root) {
        dfs(root);
        i = 0;
    }

    int next() {
        return arr[i++];
    }

    bool hasNext() {
        return i < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */