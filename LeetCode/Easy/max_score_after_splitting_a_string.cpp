#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int left = 0, right = 0, numOnes = 0, maxScore = 0;
        for(char ch: s){
            if (ch == '1'){
                numOnes++;
            }
        }
        for (int i=0; i<s.size()-1; ++i){
            if (s[i] == '0'){
                left += 1;
                right = numOnes;
            }
            else{
                right = --numOnes;
            }
            maxScore = maxScore > left+right ? maxScore:left+right;
        }
        return maxScore;
    }
};