#include <bits/stdc++.h>
using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int i=0; 
        
        // finding i who does not know j
        for (int j=1; j<n; ++j){
            if (knows(i, j)) i = j;
        }
        
        // check if i does not know j
        for (int j=0; j<i; ++j){
            if (knows(i, j)) return -1;
        }
        
        // check if each person knows i and i != j
        for (int j=0; j<n; ++j){
            if (i != j && !knows(j, i)) return -1;
        }
        
        return i;
    }
};