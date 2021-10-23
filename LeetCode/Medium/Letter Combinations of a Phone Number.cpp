#include <bits/stdc++.h>
using namespace std;

class Solution_R {
    void helper(string& digits, string builder, int index){
        if (index == digits.size()){
            res.push_back(builder);
            return;
        }
        
        for (char ch: keyPad[digits[index]-'0']){
            builder.push_back(ch);
            helper(digits, builder, index+1);
            builder.pop_back();
        }
    }
public:
    const vector<string> keyPad = {"", "", "abc", "def", "ghi", "jkl",
                                      "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        string builder;
        if (digits.empty()) return res;
        helper(digits, builder, 0);
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

// Time: O(N* 4^N)
// Space: O(N)