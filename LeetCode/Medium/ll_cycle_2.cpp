#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *t = head;
        ListNode* h = head;
        ListNode* e = head;
        do{
            if(!(h=h->next) || !(h=h->next)) return NULL;
            t=t->next;
        }while(t!=h);

        // cycle found - now find the entry point
        while(t!=e){
            t=t->next;
            e=e->next;
        }
        return e;
    }
};