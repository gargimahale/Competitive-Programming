#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        int minL = 0, maxR = 0, len, x;
        
        TreeNode *currNode;
        unordered_map<int, vector<int>> columnsMap;
        queue<pair<TreeNode*, int>> layer;
        
        layer.push({root, 0});

        while (layer.size()) {
            len = layer.size();
            unordered_map<int, vector<int>> tmpMap;
            for (int i = 0; i < len; i++) {
                
                currNode = layer.front().first;
                x = layer.front().second;
                tmpMap[x].push_back(currNode->val);
                minL = min(minL, x);
                maxR = max(maxR, x);

                if (currNode->left) layer.push({currNode->left, x - 1});
                if (currNode->right) layer.push({currNode->right, x + 1});

                layer.pop();
            }
            for (auto e: tmpMap) {
                sort(begin(e.second), end(e.second));
                for (int n: e.second) columnsMap[e.first].push_back(n);
            }
        }
        for (int i = minL; i <= maxR; i++) {
            res.push_back(columnsMap[i]);
        }
        return res;
    }
};