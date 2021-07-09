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

    void findKthSmallest(TreeNode* root, int k, vector<int>* kth) {
        if (!root) return;

        if (root && kth->size() < k) {
            findKthSmallest(root->left, k, kth);
            if (kth->size() < k) {
                kth->push_back(root->val);
                findKthSmallest(root->right, k, kth);
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> kth;
        findKthSmallest(root, k, &kth);
        return kth.back();
    }
};