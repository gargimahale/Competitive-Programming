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
    int getHeight(Node* root) {
        if (!root) return 0;
        int max1 = 0, max2 = 0;
        for (auto child : root->children) {
            int h = getHeight(child);

            if (h > max1) {
                max2 = max1;
                max1 = h;
            }
            else if (h > max2) {
                max2 = h;
            }
        }
        res = max(res, max1 + max2);
        return max1 + 1;
    }

public:
    int res = 0;
    int diameter(Node* root) {
        getHeight(root);
        return res;
    }
};