#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string reorderSpaces(string text) {
        bool seen = false;
        int w = 0, s = 0;
        string word;
        vector<string> words;
        if (text.empty()) {
            return word;
        }
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == ' ') {
                ++s;
                if (word.size() != 0) {
                    words.push_back(word);
                    word = "";
                }
            }
            else {
                word += text[i];
            }
        }

        if (word.size() != 0) {
            words.push_back(word);
        }

        if (words.size() == 1) {
            return words.back() + string(s, ' ');
        }

        string res;
        int gap = s / (words.size() - 1), extra = s % (words.size() - 1);
        for (auto w : words) {
            res += w + string(gap, ' ');
        }

        return res.substr(0, res.size() - gap) + string(extra, ' ');
    }
};