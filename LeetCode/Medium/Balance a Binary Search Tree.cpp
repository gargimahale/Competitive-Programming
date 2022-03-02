#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time: O(N), Space: O(N)
class Solution {
    void dfs(TreeNode* root){
        if (root){
            dfs(root->left);
            vec.push_back(root->val);
            dfs(root->right);
        }
    }
    
    TreeNode* treeBuilder(int start, int end){
        if (start > end){
            return NULL;
        }
        
        int mid = start + (end - start)/2;
        TreeNode* r = new TreeNode(vec[mid]);
        r->left = treeBuilder(start, mid-1);
        r->right = treeBuilder(mid+1, end);
        return r;
    }
    
public:
    vector<int> vec;
    TreeNode* balanceBST(TreeNode* root) {
        if (!root){
            return NULL;
        }
        dfs(root);
        TreeNode* newRoot = treeBuilder(0, vec.size()-1);
        return newRoot;
    }
};


// DSW Algorithm - Time: O(N), Space: O(1)
// Ref: https://csactor.blogspot.com/2018/08/dsw-day-stout-warren-algorithm-dsw.html
// Ref: Votrubac: https://leetcode.com/problems/balance-a-binary-search-tree/discuss/541785/C%2B%2BJava-with-picture-DSW-O(n)orO(1)
int makeVine(TreeNode *grand, int cnt = 0) {
	auto n = grand->right;
	while (n != nullptr) {
		if (n->left != nullptr) {
			auto old_n = n;
			n = n->left;
			old_n->left = n->right;
			n->right = old_n;
			grand->right = n;
		}
		else {      
			++cnt;
			grand = n;
			n = n->right;
		}
	}
	return cnt;
}

void compress(TreeNode *grand, int m) {
	auto n = grand->right;
	while (m-- > 0) {
		auto old_n = n;
		n = n->right;
		grand->right = n;
		old_n->right = n->left;
		n->left = old_n;
		grand = n;
		n = n->right;
	}
}

TreeNode* balanceBST(TreeNode *root) {
	TreeNode grand;
	grand.right = root;
	auto cnt = makeVine(&grand);
	int m = pow(2, int(log2(cnt + 1))) - 1;
	compress(&grand, cnt - m);
	for (m = m / 2; m > 0; m /= 2)
		compress(&grand, m);
	return grand.right;
}


