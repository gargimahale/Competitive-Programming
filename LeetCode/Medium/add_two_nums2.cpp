#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverseList(ListNode* p) {
        ListNode* curr = nullptr;
        while (p) {
            ListNode* temp = p->next;
            p->next = curr;
            curr = p;
            p = temp;
        }
        return curr;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* p = nullptr;
        int c = 0;
        while (l1 || l2) {
            if (l1) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                c += l2->val;
                l2 = l2->next;
            }
            p = new ListNode(c % 10, p);
            c /= 10;
        }
        if (c) {
            return new ListNode(c, p);
        }
        return p;
    }
};
