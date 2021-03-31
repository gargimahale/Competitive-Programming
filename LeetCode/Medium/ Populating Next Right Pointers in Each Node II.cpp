#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// TC: O(n), SC: O(n)

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (!root)
            return NULL;

        queue<Node *> Q;
        Q.push(root);
        Q.push(NULL);
        Node *prev = NULL;

        while (!Q.empty())
        {
            Node *temp = Q.front();
            Q.pop();
            if (!temp)
            {
                if (!Q.empty())
                {
                    Q.push(NULL);
                }
                prev->next = NULL;
                prev = NULL;
            }
            else
            {
                if (prev)
                {
                    prev->next = temp;
                }
                prev = temp;
                if (temp->left)
                {
                    Q.push(temp->left);
                }
                if (temp->right)
                {
                    Q.push(temp->right);
                }
            }
        }
        return root;
    }
};

// TC: O(n), SC: O(1)

