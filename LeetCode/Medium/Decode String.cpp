#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string decodeStringHelper(string& s, int& i) {
        string result;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.length() && isdigit(s[i])) {
                    k = k * 10 + s[i++] - '0';
                }
                i++;
                string r = decodeStringHelper(s, i);
                while (k-- > 0) {
                    result += r;
                }
                i++;
            }
            else {
                result += s[i++];
            }
        }
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeStringHelper(s, i);
    }
};