#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    int goodNodes(TreeNode *root, int maxVal = INT_MIN){
        if (!root){
            return 0;
        }
        
        if (root->val >= maxVal){
            return 1 + goodNodes(root->left, max(maxVal, root->val)) + goodNodes(root->right, max(root->val, maxVal));
        }
        return goodNodes(root->left, max(maxVal, root->val)) + goodNodes(root->right, max(root->val, maxVal));
    }
};

int main(){
    Solution sol;
    struct TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout << sol.goodNodes(root) << "\n";
}