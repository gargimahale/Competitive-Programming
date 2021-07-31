#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1, j = b.length() - 1, c = 0;
        while (i >= 0 || j >= 0) {
            int sum = c;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            c = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if (c) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};

// OR

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        string res;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? (a[i--] - '0') : 0;
            c += j >= 0 ? (b[j--] - '0') : 0;
            res = char(c % 2 + '0') + res;
            c /= 2;
        }
        return res;
    }
};