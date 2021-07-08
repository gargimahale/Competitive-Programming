#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int size = Q.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                auto ele = Q.front();
                Q.pop();
                row[i] = ele->val;

                if (ele->children.size() > 0) {
                    for (int i = 0; i < ele->children.size(); ++i) {
                        Q.push(ele->children[i]);
                    }
                }
            }
            ans.push_back(row);
        }

        return ans;
    }
};