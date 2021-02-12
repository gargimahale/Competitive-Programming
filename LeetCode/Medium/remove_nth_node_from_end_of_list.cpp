#include<bits/stdc++.h>
using namespace std;

// Two pointer method

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode(-1,head);
        ListNode* p1 = head;
        ListNode* p2 = prev;
        int count = 0;
        while (p1) {
            p1 = p1->next;
            if(count++ >= n) {
                p2 = p2->next;
            }
        }
        p2->next = p2->next->next;
        return prev->next;
    }
};

// OR

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode();
    dummy -> next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    while(n) fast = fast -> next, n --;
    while(fast -> next != NULL) fast = fast->next, slow = slow->next;
    slow -> next = slow -> next -> next;
    return dummy->next;
}