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
    int maxDepth(TreeNode* root) {
        return !root? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// TC: O(n), SC: O(n)


class Solution {
public:
    int maxDepth(TreeNode* root) {
        int height = 0;
        if (!root) return height;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int n = Q.size();
            ++height;
            for (int i = 0; i < n; ++i) {
                auto curr = Q.front(); Q.pop();

                if (curr->left) {
                    Q.push(curr->left);
                }

                if (curr->right) {
                    Q.push(curr->right);
                }
            }
        }
        return height;
    }
};

// TC: O(N), SC: O(N)
// faster implementation as queue uses deque as its container
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (!root){
            return depth;
        }
        deque<TreeNode*> Q;
        Q.push_back(root);
        
        while(!Q.empty()){
            int size = Q.size();
            ++depth;
            for (int i = 0; i<size; ++i){
                TreeNode* curr = Q.front();
                Q.pop_front();
                
                if (curr->left){
                    Q.push_back(curr->left);
                }
                
                if (curr->right){
                    Q.push_back(curr->right);
                }
            }
        }
        return depth;
    }
};