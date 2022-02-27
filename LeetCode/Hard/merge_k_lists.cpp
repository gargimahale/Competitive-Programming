#include <bits/stdc++.h>
using namespace std;

// TC: O(Nlogk) - N is the number of nodes, k is the number of linkedlists
// SC: O(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return NULL;

        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
            }

            len = (len + 1) / 2;
        }

        return lists.front();
    }
};

// [[1,4,5],[1,3,4],[2,6]]

int main(void){
    Solution sol;
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    ListNode* curr = l1;
    curr->next = new ListNode(4);
    curr->next->next = new ListNode(5);
    lists.push_back(l1);

    l1 = new ListNode(1);
    curr = l1;
    curr->next = new ListNode(3);
    curr->next->next = new ListNode(4);
    lists.push_back(l1);

    l1 = new ListNode(2);
    curr = l1;
    curr->next = new ListNode(6);
    lists.push_back(l1);

    ListNode* res = sol.mergeKLists(lists);
    ListNode* t = res;
    while(t){
        cout << t->val << " ";
        t = t->next;
    }
    delete t;
}