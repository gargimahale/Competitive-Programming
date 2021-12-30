#include <climits>
#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);

        int new_price = root->val + left + right;
        maxSum = max(maxSum, new_price);

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

// TC: O(N)
// SC: O(H)
