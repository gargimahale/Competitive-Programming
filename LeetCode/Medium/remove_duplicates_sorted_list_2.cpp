#include<bits/stdc++.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* curr = head;
        while (curr) {
            while (curr && curr->next && curr->next->val == curr->val) curr = curr->next;
            if (pre->next == curr) pre = pre->next;
            else pre->next = curr->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};