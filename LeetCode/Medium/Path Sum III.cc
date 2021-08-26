#include <unordered_map>
#include <iostream>
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
    void dfs(TreeNode* root, int curr, int sum, int& count){
        if (!root){
            return;
        }
        
        curr += root->val;
        
        if (mp.find(curr - sum) != mp.end()){
            count += mp[curr-sum];
        }
        
        mp[curr]++;
        
        dfs(root->left, curr, sum, count);
        dfs(root->right, curr, sum, count);
        
        mp[curr]--;
        
    }
public:
    unordered_map<int, int> mp;
    
    int pathSum(TreeNode* root, int sum) {
        mp[0]++;
        int count = 0;
        dfs(root, 0, sum, count);
        return count;
    }
};