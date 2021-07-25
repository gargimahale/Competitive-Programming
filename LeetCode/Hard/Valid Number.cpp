#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        if (len == 0) return 0;

        bool exp = false, sign = false, dec = false, num = false;

        for (char& ch : s) {
            if (ch >= '0' && ch <= '9') {
                num = true;
            }
            else if (ch == 'e' || ch == 'E') {
                if (exp || !num) {
                    return false;
                }
                else {
                    exp = true;
                    sign = false;
                    num = false;
                    dec = false;
                }
            }
            else if (ch == '+' || ch == '-') {
                if (sign || num || dec) {
                    return false;
                }
                else {
                    sign = true;
                }
            }
            else if (ch == '.') {
                if (dec || exp) {
                    return false;
                }
                else {
                    dec = true;
                }
            }
            else return false;
        }
        return num;
    }
};
