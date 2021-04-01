#include <bits/stdc++.h>
using namespace std;


// TC: O(n), SC: O(1)
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *dummy = head;
        while (dummy && dummy->next)
        {
            swap(dummy->val, dummy->next->val);
            dummy = dummy->next->next;
        }

        return head;
    }
};