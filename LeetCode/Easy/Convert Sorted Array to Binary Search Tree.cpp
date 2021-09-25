#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* helperToBST(vector<int>& nums, int s, int e){
        if (s > e)
            return nullptr;
        else{
            int mid = (s + e + 1)/2;
            TreeNode* newHead = new TreeNode(nums[mid]);
            newHead->left = helperToBST(nums, s, mid-1);
            newHead->right = helperToBST(nums, mid+1, e);
            return newHead;
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return NULL;
        }
        
        return helperToBST(nums, 0, n-1);
    }
};