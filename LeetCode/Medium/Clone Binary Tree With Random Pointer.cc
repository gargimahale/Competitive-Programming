#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

class Solution {
public:
    unordered_map<Node*, NodeCopy*> mp;
    
    NodeCopy* dfs(Node* root){
        if (!root){
            return NULL;
        }
        
        if (mp.find(root) != mp.end()){
            return mp[root];
        }
        
        NodeCopy* newNode = new NodeCopy(root->val);
        mp[root] = newNode;
        newNode->left = dfs(root->left);
        newNode->right = dfs(root->right);
        newNode->random = dfs(root->random);
        
        return newNode;
        
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return dfs(root);
    }
};

