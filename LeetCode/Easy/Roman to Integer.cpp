#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping = {{'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int answer = mapping[s.back()];

        for (int i = s.size() - 2; i >= 0; --i) {
            if (mapping[s[i]] < mapping[s[i + 1]]) {
                answer -= mapping[s[i]];
            }
            else {
                answer += mapping[s[i]];
            }
        }
        return answer;
    }
};