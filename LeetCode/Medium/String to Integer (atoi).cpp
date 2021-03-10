#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        long ans = 0;
        if (s.length() == 0) return 0;

        //Discard whitespaces in the beginning
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check if optional sign if it exists
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        // Build the result and check for overflow/underflow condition
        while(i < n && isdigit(s[i])){
            ans = ans*10 + (s[i++]-'0');
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;
        }
        return ans*sign;
    }
};