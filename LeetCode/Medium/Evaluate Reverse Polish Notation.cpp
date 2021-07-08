#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expr_result;
        for (string token : tokens) {
            if (token == "*" || token == "/" || token == "-" || token == "+") {

                // two operands required
                int y = expr_result.top();
                expr_result.pop();
                int x = expr_result.top();
                expr_result.pop();

                if (token == "+") {
                    expr_result.push(x + y);
                }
                else if (token == "-") {
                    expr_result.push(x - y);
                }
                else if (token == "*") {
                    expr_result.push(x * y);
                }
                else if (token == "/") {
                    expr_result.push(x / y);
                }

            }
            else {
                // token is a number
                expr_result.push(stoi(token));
            }
        }
        return expr_result.top();
    }
};