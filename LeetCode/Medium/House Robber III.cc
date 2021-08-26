#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int tryRob(TreeNode* root, int& l, int& r){
        if (!root){
            return 0;
        }
        
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(l+r, root->val+ll+lr+rl+rr);  
    }
public:
    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
};

	