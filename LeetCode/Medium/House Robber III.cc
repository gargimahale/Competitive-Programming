#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    pair<int, int> dfs(TreeNode* root){
        if (!root){
            return {0, 0};
        }
        
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        return {
            root->val + left.second + right.second,
            max(left.first, left.second) + max(right.first, right.second)
        };
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> p = dfs(root);
        return max(p.first, p.second);
    }
};
	