#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root){
            return NULL;
        }
        
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else{
            if (root->left == NULL && root->right == NULL){
                delete root, root = NULL;
            }
            else if(root->left == NULL){
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
            }
            else if (root->right == NULL){
                TreeNode* tmp = root;
                root = root->left;
                delete tmp;
            }
            else{
                TreeNode* tmp = findMin(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        return root;
    }
};