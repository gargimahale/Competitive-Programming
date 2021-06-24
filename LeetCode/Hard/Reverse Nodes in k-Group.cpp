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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while (true) {
            ListNode* cursor = after;
            for (int i = 0; i < k; i++) {
                if (cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for (int i = 0; i < k; i++) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};

