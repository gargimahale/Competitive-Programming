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

    int calculateLongestSeq(TreeNode* root, TreeNode* parent, int len) {
        if (!root) return len;

        len = (parent && root->val == parent->val + 1) ? ++len : 1;
        return max({len, calculateLongestSeq(root->left, root, len),
                    calculateLongestSeq(root->right, root, len)
                   });
    }

    int longestConsecutive(TreeNode* root) {
        return calculateLongestSeq(root, nullptr, 0);
    }
};