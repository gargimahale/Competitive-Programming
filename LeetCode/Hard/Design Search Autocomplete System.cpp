#include <bits/stdc++.h>
using namespace std;

class AutocompleteSystem {
public:
    struct TrieNode{
        string str;
        int count;
        unordered_map<char, TrieNode*> next;
        TrieNode(): str(""), count(0) {}
    };
    
    void insert(string& s, TrieNode* root, int times){
        TrieNode* curr = root;
        for (int i = 0; i < s.size(); ++i){
            if (!curr->next.count(s[i])){
                curr->next[s[i]] = new TrieNode();
            }
            curr = curr->next[s[i]];
        }
        curr->count += times;
        curr->str = s;
    }
    
    void dfs(TrieNode* temp){
        if (temp->str != ""){
            Q.push({temp->str, temp->count});
        }
        
        for (auto& ele: temp->next){
            dfs(ele.second);
        }
    }
    
    struct comp{
        bool operator() (pair<string, int>& a, pair<string, int>& b){
            return a.second < b.second || a.second == b.second && a.first > b.first;      
        }
    };
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> Q;
    TrieNode* root, *curr;
    string s;
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); ++i){
            insert(sentences[i], root, times[i]);
        }
        curr = root;
    }
    
    vector<string> input(char c) {
        Q = priority_queue<pair<string, int>, vector<pair<string, int>>, comp> ();
        if (c == '#'){
            insert(s, root, 1);
            s = "";
            // start searching from the beginning node for the next sentence
            curr = root;
            return {};
        }
        
        s += c;
        if (curr && curr->next.count(c)){
            curr = curr->next[c];
        }
        else{
            // curr node is null so empty result for any further characters in current input 
            curr = NULL;
            return {};
        }
        
        if (curr->str != ""){
            Q.push({curr->str, curr->count});
        }
        
        for (auto& ele: curr->next){
            dfs(ele.second);
        }
        
        vector<string> res;
        while(!Q.empty() && res.size() < 3){
            res.push_back(Q.top().first);
            Q.pop();
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */