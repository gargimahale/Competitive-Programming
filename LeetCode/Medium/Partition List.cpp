#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode* l = &left, *r = &right;
        
        while(head){
            if (head->val < x){
                l->next = head;
                l = head;
            }
            else{
                r->next = head;
                r = head;
            }
            head = head->next;
        }
        
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};