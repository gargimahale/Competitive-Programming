#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int closestValue(TreeNode *root, double target) {
        int val, close = root->val;
        
        while (root) {
            val = root->val;
            close = abs(val - target) < abs(close - target) ? val : close;
            root = target < root->val ? root->left : root->right;
        }
        return close;
    }
};