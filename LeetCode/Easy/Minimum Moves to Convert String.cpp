#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(string s, int moves = 0) {
        int n = s.size(), i = 0, count = 0;
        bool found = false;
        while(i < n){
            while(s[i] == 'O') ++i;
            
            int count = 0;
            while(i < n && count < 3){
                if (s[i] == 'X' && !found){
                    ++moves;
                    found = true;
                }
                ++count;
                ++i;
            }
            
            count = 0;
            found = false;
        }
        return moves;
    }
};