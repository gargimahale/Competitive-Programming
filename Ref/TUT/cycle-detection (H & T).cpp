#include<bits/stdc++.h>
using namespace std;


//Definition of cycle for singly-linked list.
// Floyd's cycle finding algorithm also known as the tortoise and hare algorithm

/*
The general idea is to have two pointers which you advance through the list at different rates. It can be shown that if there is a loop, then eventually both pointers will point to the same node. Not only will they eventually point to the same node, they will do so in O(n) steps.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* tortoise = head;
        ListNode* hare = head;
        do{
            if(!(hare=hare->next) || !(hare=hare->next)) return false;
            tortoise = tortoise->next;
        }while(tortoise!= hare);
        return true;
    }
};