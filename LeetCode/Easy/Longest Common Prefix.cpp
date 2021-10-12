#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0){
            return "";
        }
        
        if (n == 1){
            return strs[0];
        }
        
        for (int j = 0; ;++j){
            for (int i = 1; i<n; ++i){
                if (strs[i].size() < j || (strs[i][j] != strs[i-1][j])){
                    return strs[i].substr(0, j);
                }
            }
        }
    }
};

// Time: O(N), Space: O(S)
class Solution_1 {
public:
    class Trie{
    public:
        unordered_map<char, Trie*> child;
        bool isWord = false;
        
        void insert(string& word){
            Trie* node = this;
            for (char& ch: word){
                if (node->child.find(ch) == node->child.end()){
                    node->child[ch] = new Trie();
                }
                node = node->child[ch];
            }
            node->isWord = true;
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (!n){
            return "";
        }
        
        if (n == 1){
            return strs[0];
        }
        
        Trie* trie = new Trie();
        for (string& word: strs){
            trie->insert(word);
        }
        
        string res = "";
        while(trie && !trie->isWord && (trie->child.size() == 1)){
            auto it = trie->child.begin();
            res += it->first;
            trie = it->second;
        }
        return res;
    }
};
