#include <bits/stdc++.h>
using namespace std;

// Two pointer method

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// TC: O(N+M), SC: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};

// TC: O(N+M), SC: O(1)
class Solution {
    int getLength(ListNode* a){
        int len = 0;
        while(a){
            ++len;
            a = a->next;
        }
        return len;
    }
    
    void traverseByKUnits(ListNode** a, int& k){
        while(k-- && (*a)){
            (*a) = (*a)->next;
        }
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA && !headB) return headA;
        if(!headA) return headB; 
        if (!headB) return headA;
        
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        int k = abs(len1-len2);
        
        if (k > 0){
            if (len1 > len2)
                traverseByKUnits(&headA, k);
            else
                traverseByKUnits(&headB, k);
        }
        
        while(headA && headB){
            if (headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};