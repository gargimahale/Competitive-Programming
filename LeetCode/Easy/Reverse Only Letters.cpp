#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, n = S.size(), j = n-1;
        if (n <= 1){
            return S;
        }
        
        while(i <= j){
            while(i < j && !isalpha(S[i])) ++i;
            while(j > i && !isalpha(S[j])) --j;
            swap(S[i++], S[j--]);
        }
        return S;
    }
};