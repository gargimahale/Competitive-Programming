#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char op = '+';
        int num;
        istringstream iss(s);
        
        while(iss >> num){
            if (op == '+'){
                stk.push(num);
            }
            else if (op == '-'){
                stk.push(-num);
            }
            else{
                int last = stk.top();
                stk.pop();
                if (op == '*'){
                    last *= num;
                }
                if (op == '/'){
                    last /= num;
                }
                stk.push(last);
            }
            iss >> op;
        }
        
        num = 0;
        while(!stk.empty()){
            num += stk.top();
            stk.pop();
        }
        return num;
    }
};

// TC: O(N)
// SC: O(N)