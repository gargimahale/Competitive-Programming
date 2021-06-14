#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq (begin(sticks), end(sticks));
        int sum = 0;
        while (pq.size() > 1) {
            int a1 = pq.top();
            pq.pop();
            int a2 = pq.top();
            pq.pop();
            sum += a1 + a2;
            pq.push(a1 + a2);
        }
        return sum;
    }
};

// TC: O(nlogn)
// SC: O(n)