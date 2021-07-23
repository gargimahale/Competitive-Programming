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
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int i = 0, j = 0;

        while (head) {
            if (i < m - 1) {
                ++i;
            }
            else {
                j = 0;
                while (j < n && head->next) {
                    head->next = head->next->next;
                    ++j;
                }
                i = 0;
            }
            head = head->next;
        }
        return dummy->next;
    }
};