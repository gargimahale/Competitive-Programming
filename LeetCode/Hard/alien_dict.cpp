#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool buildGraph(vector<string>& words, vector<vector<int>>& graph, unordered_map<char, int>& indegree){
        for (auto word: words){
            for (auto ch: word){
                indegree[ch] = 0;
            }
        }
        
        for (int i = 1; i < words.size(); ++i){
            string pre = words[i-1], curr = words[i];
            int pre_sz = pre.size(), curr_sz = curr.size();
            
            int j = 0;
            
            while(j < pre_sz && j < curr_sz && pre[j] == curr[j]){
                ++j;
            }
            
            if (j < pre_sz && j == curr_sz) return false;
            if (j < curr_sz && j < pre_sz){
                graph[pre[j]-'a'].push_back(curr[j]-'a');
                indegree[curr[j]]++;
            }
        }
        return true;
    }
public:    
    string alienOrder(vector<string>& words) {
        string ans;
        int n = words.size();
        
        if (n == 0){
            return ans;
        }
        
        vector<vector<int>> graph(26, vector<int>());
        unordered_map<char, int> indegree;
        
        if (!buildGraph(words, graph, indegree)){
            return ans;
        }
        
        deque<int> Q;
        for (auto& e: indegree){
            if (e.second == 0){
                Q.push_back(e.first-'a');
            }
        }
        
        while (!Q.empty()){
            int curr = Q.front();
            Q.pop_front();
            
            ans.push_back(curr + 'a');
            
            for (auto v: graph[curr]){
                if (--indegree[v+'a'] == 0){
                    Q.push_back(v);
                }
            }
        }
        return indegree.size() == ans.size() ? ans: "";
    }
};