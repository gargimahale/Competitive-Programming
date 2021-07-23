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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {

        if (!head) return NULL;
        ListNode* curr = head;
        unordered_map<int, int> mp;

        // gets the freq of the elements present int the linkedList
        while (curr) {
            ++mp[curr->val];
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0);
        curr = dummy;

        while (head) {
            if (mp[head->val] == 1) {
                curr->next = head;
                curr = curr->next;
            }
            head = head->next;
        }

        curr->next = nullptr;
        return dummy->next;
    }
};