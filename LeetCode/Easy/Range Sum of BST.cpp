#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time: O(N), Space: O(N)
class Solution {
    void dfs(TreeNode* root, int& sum, int& low, int& high){
        if (!root){
            return;
        }
        dfs(root->left, sum, low, high);
        if (root->val >= low && root->val <= high)
            sum += root->val;
        dfs(root->right, sum, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if (!root){
            return sum;
        }
        dfs(root, sum, low, high);
        return sum;
    }
};