#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        istringstream iss(s);
        char op = '+';
        int a;
        while (iss >> a) {
            if (op == '+') {
                stk.push(a);
            }
            else if (op == '-') {
                stk.push(-a);
            }
            else {
                int last = stk.top();
                stk.pop();
                if (op == '*') {
                    last *= a;
                }
                else {
                    last /= a;
                }
                stk.push(last);
            }
            iss >> op;
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

// TC: O(N)
// SC: O(N)