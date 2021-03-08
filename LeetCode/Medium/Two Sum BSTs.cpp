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
    vector<int> tree;
    
    void flattenTree(TreeNode* r){
        if (!r) return;
        flattenTree(r->left);
        tree.push_back(r->val);
        flattenTree(r->right);
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        tree.clear();
        flattenTree(root1);
        flattenTree(root2);
        
        int l = 0, r = tree.size()-1;
        while(l < r){
            if (tree[l] + tree[r] == target) return true;
            else if (tree[l] + tree[r] < target) ++l;
            else --r;
        }
        return false;
        
    }
};