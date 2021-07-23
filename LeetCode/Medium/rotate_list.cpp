#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* RotateRight(ListNode* head, int k) {
    if (!head) return NULL;

    ListNode* curr = head;
    int size = 1;

    while (curr->next) {
        size++;
        curr = curr->next;
    }

    curr->next = head;

    // for k>size
    k = k % size;

    while (--size >= k)
        curr = curr->next;

    ListNode* first = curr->next;
    curr->next = NULL;

    return first;
}

