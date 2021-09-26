#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Trie {
public:
	Trie* next[26] = {};
	bool isWord = false;
    /** Initialize your data structure here. */

    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char& ch: word){
        	ch -= 'a';
        	if (!node->next[(int)ch]){
        		node->next[(int)ch] = new Trie();
        	}
        	node = node->next[(int)ch];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char& ch: word){
        	ch -= 'a';
        	if (!node->next[(int)ch]){
        		return false;
        	}
        	node = node->next[(int)ch];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char& ch: prefix){
        	ch -= 'a';
        	if (!node->next[(int)ch]){
        		return false;
        	}
        	node = node->next[(int)ch];
        }
        return true;
    }
};

int main(void){
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("ape");
    obj->insert("ale");
    cout << obj->search("ant") << "\n";
    cout << obj->search("ape") << "\n";
    cout << obj->startsWith("ap") << "\n";
}