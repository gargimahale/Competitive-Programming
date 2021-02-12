#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode();
        PolyNode* curr = dummy;
        
        while(poly1 && poly2){
            int pow1 = poly1->power, pow2 = poly2->power; 
            if (poly1->power == poly2->power){
                int netCoeff = poly1->coefficient+poly2->coefficient;
                if (netCoeff != 0){
                    curr->next = new PolyNode(netCoeff, pow1);
                    curr = curr->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }  
            else if (pow1>pow2){
                curr->next = new PolyNode(poly1->coefficient, pow1);
                curr = curr->next;
                poly1 = poly1->next;
            }

            else if (pow1<pow2){
                curr->next = new PolyNode(poly2->coefficient, pow2);
                curr = curr->next;
                poly2 = poly2->next;
            }
            
        }
        while(poly1){
            curr->next = new PolyNode(poly1->coefficient, poly1->power);
            poly1 = poly1->next;
            curr = curr->next;
        }
        while(poly2){
            curr->next = new PolyNode(poly2->coefficient, poly2->power);
            poly2 = poly2->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};