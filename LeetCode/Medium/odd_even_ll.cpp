#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    ListNode * oddevenList(ListNode *head){
        if(!head) return head;
        ListNode *a = head, *b = head->next, *temp = b;
        while(a && b && a->next && b->next){
            a->next = b->next;
            a=a->next;
            b->next=a->next;
            b=b->next;
        }
        a->next = temp;
        return head;
    }
};