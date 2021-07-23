#include <bits/stdc++.h>
using namespace std;

// Two pointer method

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};

// TC: O(N+M), SC: O(1)

class Solution {
    int getLength(ListNode* head) const {
        int len = 1;
        while (head) {
            len += ((head = head->next) != NULL);
        }
        return len;
    }

    void advanceByK(int k, ListNode** head) {
        while (k--) {
            (*head) = (*head)->next;
        }
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        int len1 = getLength(headA), len2 = getLength(headB);

        advanceByK(abs(len2 - len1), len1 > len2 ? &headA : &headB);
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

// TC: O(N+M), SC: O(1)