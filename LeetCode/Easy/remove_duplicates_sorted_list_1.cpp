#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* curr = head;
    while (curr && curr->next) {
        ListNode* next = curr->next;
        if (curr->val == curr->next->val) {
            curr->next = next->next;
            delete(next);
        }
        else curr = curr->next;
    }
    return head;
}