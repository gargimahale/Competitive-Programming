#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0){
            return "";
        }
        
        if (n == 1){
            return strs[0];
        }
        
        for (int j = 0; ;++j){
            for (int i = 1; i<n; ++i){
                if (strs[i].size() < j || (strs[i][j] != strs[i-1][j])){
                    return strs[i].substr(0, j);
                }
            }
        }
    }
};