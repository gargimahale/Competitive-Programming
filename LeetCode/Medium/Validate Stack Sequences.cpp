#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0, j = 0;
        while(i < pushed.size()){
            stk.push(pushed[i++]);
            while(!stk.empty() && popped[j] == stk.top()){
                stk.pop();
                ++j;
            }
        }
        return stk.empty();
    }
};