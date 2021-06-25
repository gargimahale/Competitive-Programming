#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* children[26];
    bool endOfWord;

    Trie(): endOfWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children[i])
                delete children[i];
        }
    }

    void insert(string word) {
        Trie* curr = this;
        for (char ch : word) {
            if (curr->children[ch - 'a'] == nullptr) {
                curr->children[ch - 'a'] = new Trie();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->endOfWord = true;
    }
};

class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j, unordered_set<string>& result, Trie* trie, string s) {
        char ch = board[i][j];
        if (ch == '$') return;
        board[i][j] = '$';
        Trie* t = trie->children[ch - 'a'];
        if (t) {
            string ss = s + ch;
            if (t->endOfWord) result.insert(ss);
            if (i < board.size() - 1) dfs(board, i + 1, j, result, t, ss);
            if (i > 0) dfs(board, i - 1, j, result, t, ss);
            if (j < board[0].size() - 1) dfs(board, i, j + 1, result, t, ss);
            if (j > 0) dfs(board, i, j - 1, result, t, ss);
        }
        board[i][j] = ch;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0) return {};
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }

        unordered_set<string> result;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, result, &trie, "");
            }
        }

        vector<string> arr(begin(result), end(result));
        return arr;
    }
};