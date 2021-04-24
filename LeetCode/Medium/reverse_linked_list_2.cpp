#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int start, int end) {
        if (start == end || !head){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        int pos = 1;
        while(pos < start){
            prev = prev ->next;
            pos++;
        }

        ListNode* workPtr = prev->next;
        while(start < end){
            ListNode* NodeExtract = workPtr->next;
            workPtr->next = NodeExtract->next;
            NodeExtract->next = prev->next;
            prev->next = NodeExtract;
            start++;
        }
        return dummy->next;
    }
};