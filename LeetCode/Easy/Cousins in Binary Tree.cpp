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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});

        int parent = -1;

        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; ++i) {
                auto ele = Q.front();
                Q.pop();

                if (ele.first->val == x || ele.first->val == y) {
                    if (parent != -1) {
                        if (parent == ele.second) {
                            return false;
                        }
                        return true;
                    }
                    parent = ele.second;
                }

                if (ele.first->left) Q.push({ele.first->left, ele.first->val});
                if (ele.first->right) Q.push({ele.first->right, ele.first->val});
            }

            if (parent != -1) {
                return false;
            }
        }
        return false;
    }
};