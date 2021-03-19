#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<string> topKFrequent(vector<string> &words, int k){
        unordered_map<string, int> freq;
        for (auto w : words) freq[w]++;

        auto comp = [&](auto a, auto b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };

        typedef priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> my_priority_queue_t;
        my_priority_queue_t pq(comp);

        for (auto w : freq){
            pq.emplace(w.second, w.first);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> output;
        while (!pq.empty()){
            output.insert(output.begin(), pq.top().second);
            pq.pop();
        }
        
        return output;
    }
};