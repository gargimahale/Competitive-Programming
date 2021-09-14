#include <bits/stdc++.h>
using namespace std;


class Solution_R {
    void helperCombinations(string& s, string curr, int i){
        if (i == s.size()){
            res.push_back(curr);
            return;
        }
        
        int d = s[i]-'0';
        for (char ch: keyPad[d]){
            helperCombinations(s, curr+ch, i+1);
        }
    }
public:
    vector<string> res;
    const vector<string> keyPad = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                  "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if (!digits.size()){
            return res;
        }
        string builder;
        helperCombinations(digits, builder, 0);
        return res;
    }
};

class Solution_I {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> result;
        result.push_back("");

        for (auto digit : digits) {
            vector<string> tmp;
            for (auto candidate : pad[digit - '0']) {
                for (auto s : result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};