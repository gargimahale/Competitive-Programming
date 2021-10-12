#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Two pointer method
        string temp;
        for (char& ch : s) {
            if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
                temp += ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                temp += (ch - 'A' + 'a');
            }
        }
        int i = 0, j = temp.size() - 1;
        while (i <= j) {
            if (temp[i] != temp[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }
};