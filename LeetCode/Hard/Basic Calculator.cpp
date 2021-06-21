#include <bits/stdc++.h>
using namespace std;

// TC & SC: O(N)

class Solution {
public:
    int calculate(string s) {
        stack<int> signs({1});
        int ans = 0, num = 0, sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+' || c == '-') {
                ans += num * sign * signs.top();
                num = 0;
                sign = (c == '+' ? 1 : -1);
            }
            else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            }
            else if (c == ')') {
                ans += num * sign * signs.top();
                num = 0;
                signs.pop();
                sign = 1;
            }
        }
        if (num)
            ans += num * sign * signs.top();
        return ans;
    }
};