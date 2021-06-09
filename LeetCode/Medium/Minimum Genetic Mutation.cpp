#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict, visited;
        int lvl = 0;
        vector<char> choices = {'A', 'C', 'G', 'T'};

        bool found = false;
        for (auto w : bank) {
            if (w == end) {
                found = true;
            }
            dict.insert(w);
        }

        if (!found) {
            return -1;
        }

        queue<string> Q;
        Q.push(start);
        visited.insert(start);
        while (!Q.empty()) {
            ++lvl;
            int size = Q.size();
            for (int i = 0; i < size; ++i) {
                string curr = Q.front();
                Q.pop();
                for (int j = 0; j < curr.size(); ++j) {
                    string temp = curr;
                    for (char ch : choices) {
                        temp[j] = ch;

                        if (dict.find(temp) != dict.end() && !visited.count(temp)) {
                            visited.insert(temp);
                            Q.push(temp);
                            if (end == temp)
                                return lvl;
                        }
                    }
                }
            }
        }

        return -1;
    }
};