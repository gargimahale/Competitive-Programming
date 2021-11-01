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
    int length(ListNode* head){
        int c = 0;
        while(head){
            head = head->next;
            ++c;
        }
        return c;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> endpoints(2, -1);
        int len = length(head);
        if (len <= 2){
            return endpoints;
        }
        vector<int> points;
        
        int i = 1, minDist = INT_MAX;
        ListNode* curr = head->next, *prev = head;
        while(curr){
            if (curr->next && curr->val > curr->next->val && curr->val > prev->val){
                // local_maxima
                points.push_back(i);
            }
            
            else if (curr->next && curr->val < curr->next->val && curr->val < prev->val){
                // local_minima  
                points.push_back(i);
            }
            ++i;
            prev = curr;
            curr = curr->next;
        }
        
        if (points.size() < 2) return endpoints;
        
        endpoints[1] = points[points.size()-1] - points[0];
        endpoints[0] = INT_MAX;
        reverse(begin(points), end(points));
        
        for (int i = 0; i < points.size()-1; ++i){
            if (points[i] - points[i+1] < endpoints[0]){
                endpoints[0] = points[i] - points[i+1];
            }
        }
        
        
        return endpoints;
    }
};