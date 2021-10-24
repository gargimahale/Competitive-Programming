#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isValidPart(string& s){
        int hyphen = 0, N = s.size();
        for (int i = 0; i < N; ++i){
            if (isdigit(s[i])) return false;
            if (isalpha(s[i])) continue;
            if (s[i] == '-'){
                if (++hyphen > 1) return false;
                if (i-1 < 0 || !isalpha(s[i-1]) || i+1 >= N || !isalpha(s[i+1])) return false;
            }
            else if (i != N-1){
                return false;
            }
        }
        return true;
    }
public:
    int countValidWords(string s) {
        int n = s.size(), words = 0;
        istringstream iss(s);
        string part;
        
        while(iss >> part){
            words += isValidPart(part);
        }
        return words;
    }
};