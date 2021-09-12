#include <bits/stdc++.h>
using namespace std;


// Time: O(N), Space: O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int idx = 0;
        
        for (int i = 0; i<n; ++i){
            if (ch == word[i]){
                idx = i;
                break;
            }
        }
        
        reverse(begin(word), begin(word)+idx+1);
        return word;
    }
};