#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, s;
        vector<string> a;
        stringstream ss(path);

        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") {
                continue;
            }

            if (s == ".." && !a.empty()) {
                a.pop_back();
            }

            if (s != "..") {
                a.push_back(s);
            }

        }
        for (string it : a) {
            res += "/" + it;
        }
        return res.empty() ? "/" : res;
    }
};