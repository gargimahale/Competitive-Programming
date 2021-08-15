#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkWord(string& word, string& p){
        if (word.size() > p.size()) return false;
        
        for (int i = 0; i<p.length()-word.length()+1; ++i){
            if (p.substr(i, word.size()).compare(word) == 0){
                return true;
            }
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        vector<int> check(26, 0);
        int cnt = 0;
        for (string w: patterns){
            if (checkWord(w, word)){
                ++cnt;
            }
        }
        return cnt;
    }
};