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
    vector<int> nodes;
    
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    // Two pointer
    bool checkTargetExists(int k){
        int i = 0, j = nodes.size()-1;
        while(i < j){
            int sum = nodes[i]+nodes[j];
            if (sum == k) return true;
            else if (sum > k) --j;
            else ++i;
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        return checkTargetExists(k);
    }
};

// OR

class Solution {
public:
    unordered_set<int> S;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (S.count(k - root->val)) return true;
        S.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};