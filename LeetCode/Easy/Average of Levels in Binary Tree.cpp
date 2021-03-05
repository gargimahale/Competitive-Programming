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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;;
        double cnt = 0, sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if (t == nullptr){
                ans.push_back(sum/cnt);
                sum = cnt = 0;
                if (!q.empty()) q.push(nullptr);
            }
            else{
                sum += t->val;
                ++cnt;
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
            }
        }
        return ans;
    }
};