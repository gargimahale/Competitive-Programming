#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {

        // To maintain count of characters
        vector<int> cnt(26);
        for (char ch: s) ++cnt[ch-'a'];
        queue<pair<int, int>> q;
        string res;
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<26; ++i){
            if (cnt[i] > 0){
                pq.push({cnt[i], i});
            }
        }
        
        // Add them to a different queue and when the size of the 
        // queue >= k push that char back in the priority queue
        // as long as the count > 0
        while(!pq.empty()){
            auto x = pq.top(); pq.pop();
            res += 'a'+x.second;
            q.push({x.first-1, x.second});
            if (q.size() >= k){
                auto p = q.front();q.pop();
                if (p.first){
                    pq.push({p.first, p.second});
                }
            }
        }
        
        return res.size() == s.size() ? res: "";
        
    }
};