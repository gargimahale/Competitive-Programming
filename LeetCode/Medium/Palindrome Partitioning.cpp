#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string& s, int& start, int& end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> res;

    void countCombinations(string& s, vector<string>& temp, int start, int end) {
        if (start == end) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < end; ++i) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                countCombinations(s, temp, i + 1, end);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        countCombinations(s, temp, 0, s.size());
        return res;
    }
};
