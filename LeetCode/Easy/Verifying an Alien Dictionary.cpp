#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26] = {0};
        for (int i = 0; i < 26; ++i){
            mapping[order[i]-'a'] = i;
        }
        
        for (auto& w: words){
            for (char& ch: w){
                ch = mapping[ch-'a'];
            }
        }
        return is_sorted(begin(words), end(words));
    }
};