#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        int n = s.size();
        if (n == 0){
            return n;
        }
        
        char op = '+';
        int a;
        istringstream iss(s);
        
        while(iss >> a){
            if (op == '+'){
                stk.push_back(+a);
            }
            else if (op == '-'){
                stk.push_back(-a);
            }
            else{
                int last = stk.back();
                stk.pop_back();
                
                if (op == '*'){
                    last *= a;
                }
                
                if (op == '/'){
                    last /= a;
                }
                stk.push_back(last);
            }
            iss >> op;
        }
        
        int res = 0;
        while(!stk.empty()){
            res += stk.back();
            stk.pop_back();
        }
        return res;
    }
};

// TC: O(N)
// SC: O(N)