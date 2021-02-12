#include <bits/stdc++.h>

using namespace std;


// Use this https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> map;
        bool found = false;
        for (auto w: wordList){
            if (w == endWord){
                found = true;
            }
            map.insert(w);
        }
        if(!found){
            return 0;
        }
        
        queue<string> pendingNodes;
        pendingNodes.push(beginWord);
        int lvl = 0;
        while(pendingNodes.size() != 0){
            lvl++;
            int size = pendingNodes.size();
            for (int i=0; i<size; ++i){
                string current = pendingNodes.front();
                pendingNodes.pop();
                for(int j=0; j<current.size(); ++j){
                    string temp = current;
                    for (char c = 'a'; c<='z'; ++c){
                        temp[j] = c;
                        if (temp == current){
                            continue;
                        }
                        else if (endWord == temp){
                            return lvl+1;
                        }
                        else if(map.find(temp) != map.end()){
                            pendingNodes.push(temp);
                            map.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};