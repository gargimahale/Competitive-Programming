#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    
    void findKthSmallest(TreeNode* root, int& k, int& kth){
        if (!root){
            return;
        }
        findKthSmallest(root->left, k, kth);
        if (k > 0){
            --k;
            kth = root->val;
        }
        findKthSmallest(root->right, k, kth);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int kth = 0;
        findKthSmallest(root, k, kth);
        return kth;
    }
};