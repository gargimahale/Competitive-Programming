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
    ListNode* dummy = new ListNode(0), *prev = dummy;
    ListNode* reverseAtTime(ListNode* head, int parts, int k) {
        dummy->next = head;
        for (int i = 0; i < parts; ++i) {
            for (int j = 1; j < k; ++j) {
                ListNode* temp = prev->next;
                prev->next = head->next;
                head->next = head->next->next;
                prev->next->next = temp;
            }
            prev = head;
            head = head->next;
        }
        return dummy->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0, parts;
        while (curr) {
            ++cnt;
            curr = curr->next;
        }

        parts = cnt / k;
        return reverseAtTime(head, parts, k);
    }
};

// OR

// TC: O(Nlogk), SC: O(N/k)
class Solution {
public:

    ListNode* reverseLL(ListNode* start, ListNode* end) {
        ListNode* prev = end;
        while (start != end) {
            ListNode* tmp = start->next;
            start->next = prev;
            prev = start;
            start = tmp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) {
                return head;
            }
            node = node->next;
        }

        ListNode* newHead = reverseLL(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }
};


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1 || !head->next) return head;

        int n = 0;
        ListNode* curr = head;
        while (curr) {
            ++n;
            curr = curr->next;
        }

        curr = head;
        ListNode* prev = nullptr, *t1 = nullptr, *t2 = head, *next, *newHead;

        while (n >= k) {
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if (!newHead) newHead = prev;
            if (t1) t1->next = prev;
            t2->next = curr;
            t1 = t2;
            t2 = curr;
            prev = nullptr;
            n -= k;
        }
        return newHead;
    }
};