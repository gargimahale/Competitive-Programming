#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> vec;
        for (int i = 0; i<s.size(); ++i){
            if (s[i] == '('){
                vec.push_back(i);
            }
            if (s[i] == ')'){
                if (!vec.empty())
                    vec.pop_back();
                else
                    s[i] = '*';
            }
        }
        
        while(!vec.empty()){
            s[vec.back()] = '*';
            vec.pop_back();
        }
        
        s.erase(remove(begin(s), end(s), '*'), end(s));
        return s;
    }
};