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
    
    ListNode* reverseLL(ListNode* start, ListNode* end){
        ListNode* prev = end;
        while(start != end){
            ListNode* tmp = start->next;
            start->next = prev;
            prev = start;
            start = tmp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i=0; i<k; ++i){
            if (!node){
                return head;
            }
            node = node->next;
        }
        
        ListNode* newHead = reverseLL(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }
};