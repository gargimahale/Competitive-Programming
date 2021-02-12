#include<bits/stdc++.h>

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        long long sum = 0;
        for(int i=shifts.size()-1; i>=0; --i){
            S[i] = (char)97 + ((int)S[i] + (shifts[i]+sum) - 97) % (123 % 97);
            sum += shifts[i];
        }
        return S;
    }
};