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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();
            if (curr) {
                ans.emplace(ans.begin(), curr->val);
                for (auto child : curr->children) {
                    stk.push(child);
                }
            }
        }
        return ans;
    }
};