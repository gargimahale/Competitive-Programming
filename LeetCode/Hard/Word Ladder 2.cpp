#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        unordered_set<string> dict(begin(wordList), end(wordList));

        paths.push({beginWord});

        int lvl = 1, minLvl = INT_MAX;
        unordered_set<string> visited;
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > lvl) {
                // new lvl
                for (string w : visited) {
                    dict.erase(w);
                }
                visited.clear();
                if (path.size() > minLvl) {
                    break;
                }
                else {
                    lvl = path.size();
                }
            }
            string last = path.back();

            // find words with one edit difference
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    news[i] = ch;
                    if (dict.find(news) != dict.end()) {
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLvl = lvl;
                            ans.push_back(newpath);
                        } else {
                            paths.push(newpath);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(void) {
    Solution sol;
    string begin = "hit", end = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = findLadders(begin, end, wordList);
    for (auto v : ans) {
        for (auto ele : v) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}