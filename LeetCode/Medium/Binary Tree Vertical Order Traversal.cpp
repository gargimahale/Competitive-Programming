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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> Q;
        Q.push({0, root});

        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; ++i) {
                auto ele = Q.front();
                int tmp = ele.first;
                Q.pop();

                m[tmp].push_back(ele.second->val);

                if (ele.second->left) Q.push({tmp - 1, ele.second->left});
                if (ele.second->right) Q.push({tmp + 1, ele.second->right});
            }
        }

        for (auto& vec : m) {
            ans.push_back(vec.second);
        }
        return ans;
    }
};