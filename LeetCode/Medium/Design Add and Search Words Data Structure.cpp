#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
    bool word;
    Trie* children[26];
    Trie(){
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
    Trie* root = new Trie();
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    bool search(const char* word, Trie* node){
        for (int i = 0; word[i] && node; ++i){
            if (word[i] != '.'){
                node = node->children[word[i]-'a'];
            }
            else{
                Trie* temp = node;
                for (int j = 0; j<26; ++j){
                    node = temp->children[j];
                    if (search(word+i+1, node))
                        return true;
                }
            }
        }
        return node && node->word;
    }
    
    void addWord(string word) {
        Trie* node = root;
        for (char ch: word){
            if (!node->children[ch-'a']){
                node->children[ch-'a'] = new Trie();
            }
            node = node->children[ch-'a'];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */