#include <bist/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        for (int i = 0; i<names.size(); ++i){
            string val = names[i];
            int count = map[val];
            
            while(map[val] > 0){
                val = names[i] + "(" + to_string(count++) + ")";
                map[names[i]] = count;
            }
            names[i] = val;
            map[val]++;
        }
        return names;
    }
};