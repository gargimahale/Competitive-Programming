#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int getLength(ListNode* head) const {
        int len = 1;
        while (head) {
            len += ((head = head->next) != NULL);
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        if (!root) return parts;

        int len = getLength(root);
        int n = len / k, r = len % k;

        ListNode* curr = root, *prev = NULL;

        for (int i = 0; curr && i < k; ++i, --r) {
            parts[i] = curr;
            for (int j = 0; j < n + (r > 0); ++j) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
        }
        return parts;
    }
};