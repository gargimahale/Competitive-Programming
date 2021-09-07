#include <bits/stdc++.h>
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
    int findDiameter(TreeNode* root, int& dia){
        if (!root){
            return 0;
        }
        
        int left = findDiameter(root->left, dia);
        int right = findDiameter(root->right, dia);
        
        dia = max(dia, left+right);
        
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        findDiameter(root, dia);
        return dia;
    }
};