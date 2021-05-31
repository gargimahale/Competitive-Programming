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

	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (!root1) return root2;
		if (!root2) return root1;
		int n1 = root1 ? root1->val : 0;
		int n2 = root2 ? root2->val : 0;
		TreeNode* head = new TreeNode(n1 + n2);
		head->left = mergeTrees(root1->left, root2->left);
		head->right = mergeTrees(root1->right, root2->right);
		return head;
	}
};

// TC: O(M), SC: O(M)