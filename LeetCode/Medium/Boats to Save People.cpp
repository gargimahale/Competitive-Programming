#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0, j = people.size()-1;
        int boats = 0;
        sort(people.begin(), people.end());
        while(i <= j){
            if (people[i]+people[j] <= limit){
                ++i;
            }
            ++boats;
            --j;
        }
        return boats;
    }
};