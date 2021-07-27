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
    int maxDepth(Node* root) {
        int height = 0;
        if (!root) return height;
        deque<Node*> Q;
        Q.emplace_back(root);

        while (!Q.empty()) {
            int size = Q.size();
            ++height;
            while (size--) {
                auto curr = Q.front(); Q.pop_front();
                if (curr->children.size() > 0) {
                    for (auto& child : curr->children) {
                        Q.emplace_back(child);
                    }
                }
            }
        }
        return height;
    }
};