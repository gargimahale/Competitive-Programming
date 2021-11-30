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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int size = Q.size();
            double cnt = 0, sum = 0;

            for (int i = 0; i < size; ++i) {
                ++cnt;
                auto ele = Q.front();
                Q.pop();
                sum += ele->val;

                if (ele->left) Q.push(ele->left);
                if (ele->right) Q.push(ele->right);
            }
            ans.push_back(sum / cnt);
        }
        return ans;
    }
};