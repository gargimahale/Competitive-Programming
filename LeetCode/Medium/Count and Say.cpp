#include <bits/stdc++.h>
using namespace std;

class Solution {
    string helperCountAndSay(string& res) const {
        string temp;
        int n = res.size();
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (i + 1 < n && res[i] == res[i + 1]) {
                ++i, ++count;
            }
            temp += to_string(count) + res[i];
        }
        return temp;
    }
public:
    string countAndSay(int n) const {
        if (n == 0) return "";

        string res = "1";
        for (int i = 1; i < n; ++i) {
            res = helperCountAndSay(res);
        }
        return res;
    }
};