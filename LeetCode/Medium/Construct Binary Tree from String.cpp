#include<bits/stdc++.h>
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
    
    TreeNode* buildTree(istringstream& in){
        int num;
        TreeNode* node;
        if (in >> num){
            node = new TreeNode(num);
        }
        char c;
        while(in >> c){
            if (c == '(' && !node->left){
                node->left = buildTree(in);
            }
            else if (c == '(' && !node->right){
                node->right = buildTree(in);
            }
            else if (c == ')') break;
        }
        return node;
    }
    
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        istringstream in(s);
        TreeNode* node = buildTree(in);
        return node;
    }
};