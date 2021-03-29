#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)

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
class Solution{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums){
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        vector<int> lft(nums.begin(), nums.begin() + mid);
        vector<int> rght(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(lft);
        root->right = sortedArrayToBST(rght);

        return root;
    }
};