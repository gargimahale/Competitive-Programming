#include <stack>
#include <string>
#include <iostream>
using namespace std;

// TC & SC: O(N)
class Solution {
public:
    static int calculate(string input) {
        int n = (int)input.size(), result = 0, sign = 1;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (isdigit(input[i])) {
                int num = input[i] - '0';
                while (i + 1 < n && isdigit(input[i + 1])) {
                    num = num * 10 + (input[++i] - '0');
                }
                result += sign * num;
            }
            else if (input[i] == '+') sign = 1;
            else if (input[i] == '-') sign = -1;
            else if (input[i] == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (input[i] == ')') {
                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();
            }
        }
        return result;
    }
};

int main(){
    cout << Solution::calculate("5+4") << "\n";
}