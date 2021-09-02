#include <vector>
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
public:
    vector<int> helper(TreeNode* root, double& res) {
        if (!root) return {0, 0};
        vector<int> left = helper(root->left, res);
        vector<int> right = helper(root->right, res);
        double avg = ((double) (left[0] + right[0] + root->val) / ((double) (1 + left[1] + right[1])));
        res = max(res, avg);
        return {left[0] + right[0] + root->val, 1 + left[1] + right[1]};
    }

    double maximumAverageSubtree(TreeNode* root) {
        double res = 0;
        helper(root, res);
        return res;
    }
};