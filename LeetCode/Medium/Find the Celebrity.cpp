#include <bits/stdc++.h>
using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celebrity = 0;
        for (int person = 1; person < n; ++person){
            if (knows(celebrity, person)){
                celebrity = person;
            }
        }
        
        for (int person = 0; person < celebrity; ++person){
            if (knows(celebrity, person)){
                return -1;
            }
        }
        
        for (int person = 0; person < n; ++person){
            if (person != celebrity && !knows(person, celebrity)){
                return -1;
            }
        }
        return celebrity;
    }
};