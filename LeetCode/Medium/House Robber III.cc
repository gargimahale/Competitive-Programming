#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class RobbedRoot{
public:
    int robbedRoot;
    int skippedRoot;
};

class Solution {
    RobbedRoot dfs(TreeNode* root){
        if (!root){
            return RobbedRoot {0, 0};
        }
        
        RobbedRoot left = dfs(root->left);
        RobbedRoot right = dfs(root->right);
        
        int robThisNode = root->val + left.skippedRoot + right.skippedRoot;
        int skipThisNode = max(left.robbedRoot, left.skippedRoot) + max(right.robbedRoot, right.skippedRoot);
        
        return RobbedRoot {robThisNode, skipThisNode};
    }
public:
    int rob(TreeNode* root) {
        RobbedRoot rob = dfs(root);
        return max(rob.robbedRoot, rob.skippedRoot);
    }
};

	