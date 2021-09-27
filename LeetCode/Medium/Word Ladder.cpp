#include <bits/stdc++.h>
using namespace std;

// Use this https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS

// Time: O(N*M*M), Space: O(W*L)
// where w: len(wordList), l = len(longestWord)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> S(begin(wordList), end(wordList));
        
        if (!S.count(endWord)){
            return 0;
        }
        
        deque<string> Q;
        Q.push_back(beginWord);
        int steps = 0;
        
        while(!Q.empty()){
            int size = Q.size();
            ++steps;
            // O(N)
            for (int i = 0; i<size; ++i){
                string curr = Q.front();
                Q.pop_front();
                
                // O(M)
                for (int j = 0; j<curr.size(); ++j){
                    string temp = curr;
                    for (char ch = 'a'; ch <= 'z'; ++ch){
                        temp[j] = ch;
                        
                        // O(M)
                        if (temp == curr) continue;
                        
                        // O(M)
                        if (temp == endWord){
                            return ++steps;
                        }
                        
                        if (S.find(temp) != S.end()){
                            Q.push_back(temp);
                            S.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};