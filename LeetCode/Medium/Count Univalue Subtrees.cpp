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

	bool dfs(TreeNode* root, int& count) {
		if (!root) return true;

		bool isLeftUni = dfs(root->left, count);
		bool isRightUni = dfs(root->right, count);

		if (isLeftUni && isRightUni) {
			if ((!root->left || (root->left->val == root->val)) && (!root->right || (root->right->val == root->val))) {
				++count;
				return true;
			}
		}

		return false;
	}

	int countUnivalSubtrees(TreeNode* root) {
		int count = 0;
		dfs(root, count);
		return count;
	}
};