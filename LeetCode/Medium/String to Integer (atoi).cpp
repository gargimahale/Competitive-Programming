#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int myAtoi(string s){
        long res = 0;

        int i = 0, sign = 1;
        if (s.size() == 0)
            return 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        while (i < s.size() && isdigit(s[i])){
            // proving bounds
            res = res * 10 + (s[i++] - '0');
            if (res * sign >= INT_MAX)
                return INT_MAX;
            if (res * sign <= INT_MIN)
                return INT_MIN;
        }
        return res * sign;
    }
};
