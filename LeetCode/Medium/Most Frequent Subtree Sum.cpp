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

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int s = dfs(root->left) + dfs(root->right) + root->val;
        max_count = max(max_count, ++cnt[s]);
        return s;
    }

public:

    int max_count = 0;
    unordered_map<int, int> cnt;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto ele : cnt) {
            if (ele.second == max_count) {
                res.emplace_back(ele.first);
            }
        }
        return res;
    }
};
