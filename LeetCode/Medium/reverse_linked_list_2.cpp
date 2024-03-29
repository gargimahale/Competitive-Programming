#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // points to the node before reversing
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // pointer to the beginning of the sublist
        ListNode* start = prev->next;
        ListNode* then = start->next;
        // prev = 1, start = 2, then = 3

        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        // 1->3->2->4->5 start = 2, then = 3
        // 1->4->3->2->5 start = 2, then = 4 (Fin)
        return dummy->next;
    }
};

// TC: O(N)
// SC: O(1)