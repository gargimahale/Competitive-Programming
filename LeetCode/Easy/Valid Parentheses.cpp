#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> stk;
        for (const char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }
            else {
                if (!stk.size()) return false;
                if (ch == ')' && stk.top() != '(') return false;
                if (ch == ']' && stk.top() != '[') return false;
                if (ch == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};