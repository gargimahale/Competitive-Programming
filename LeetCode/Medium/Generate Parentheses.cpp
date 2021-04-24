#include <bits/stdc++.h>
using namespace std;

// The total number of valid parentheses is a Catalan number
// TC: O(C(2n, n)/(n + 1))
// SC: O(n)

class Solution {
public:
    vector<string> result;
    
    void helper(string s, int n, int m){
        if (n == 0 && m == 0){
            result.push_back(s);
            return;
        }
        if (n > 0) helper(s+'(', n-1, m+1);
        if (m > 0) helper(s+')', n, m-1);
    }
        
    
    vector<string> generateParenthesis(int n) {
        helper("", n, 0);
        return result;
    }
};