#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyds Cycle detection alsogrithm

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                return true;
            }
        }
        return false;
    }
};