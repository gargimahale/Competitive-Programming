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

// TC: O(N)

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
    int deepestLeavesSum(TreeNode *root){
        int res = 0, i;
        queue<TreeNode *> Q;
        Q.push(root);
        while (Q.size()){
            for (i = Q.size() - 1, res = 0; i >= 0; --i){
                TreeNode *node = Q.front();
                Q.pop();
                res += node->val;
                if (node->right)
                    Q.push(node->right);
                if (node->left)
                    Q.push(node->left);
            }
        }
        return res;
    }
};