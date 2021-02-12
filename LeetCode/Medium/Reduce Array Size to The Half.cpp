#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int x: arr){
            ++m[x];
        }
        
        priority_queue<int> pq;
        for (auto x: m){
            pq.push(x.second);
        }
        
        int res = 0, cnt = 0;
        while(cnt * 2 < arr.size()){
            ++res;
            cnt += pq.top();
            pq.pop();
        }
        return res;
    }
};