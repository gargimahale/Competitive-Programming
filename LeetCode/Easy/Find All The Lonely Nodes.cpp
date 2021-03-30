#include <bits/stdc++.h>
using namespace std;

// TC: O(N) - N are the number of nodes; SC: O(N)

class Solution
{
public:
    vector<int> getLonelyNodes(TreeNode *root)
    {
        vector<int> lonely;
        if (!root)
            return lonely;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *node = stack.top();
            stack.pop();
            if (node->left)
            {
                stack.push(node->left);
                if (!node->right)
                    lonely.push_back(node->left->val);
            }
            if (node->right)
            {
                stack.push(node->right);
                if (!node->left)
                    lonely.push_back(node->right->val);
            }
        }
        return lonely;
    }
};