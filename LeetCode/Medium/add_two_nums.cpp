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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* answer = new ListNode(0);
        ListNode* newHead = answer;
        int c = 0;
        while (c || l1 || l2) {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            answer->next = new ListNode(c % 10);
            answer = answer->next;
            c /= 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return newHead->next;
    }
};