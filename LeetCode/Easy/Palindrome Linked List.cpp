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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            slow = slow->next;
        }

        slow = reverse(slow);
        fast = head;

        while (slow) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};

// TC: O(N), SC: O(1)