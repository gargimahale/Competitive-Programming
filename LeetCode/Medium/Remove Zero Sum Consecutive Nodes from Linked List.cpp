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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* curr, *prev, *start;
        start = new ListNode();
        start -> next = head;
        prev = start;
        curr = head;
        int sum = 0;
        while(curr){
            sum += curr->val;
            if (sum == 0){
                prev->next = curr->next;
            }
            curr = curr->next;
            
            if (curr == nullptr){
                prev = prev->next;
                if (prev == nullptr){
                    break;
                }
                curr = prev->next;
                sum = 0;
            }
        }
        return start->next;
    }
};