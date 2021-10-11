#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// Floyds Cycle detection algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};