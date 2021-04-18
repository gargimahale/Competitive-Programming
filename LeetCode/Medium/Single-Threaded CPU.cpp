#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef pair<int, int> T; // processing time, index
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        // sort first by processing time and then by index
        priority_queue<T, vector<T>, greater<>> pq;

        // i -> ptr
        long N = tasks.size(), time = 0, i = 0;

        // append the idx to each task
        for (int i = 0; i < N; ++i) {
            tasks[i].push_back(i);
        }

        sort(begin(tasks), end(tasks));
        vector<int> res;

        // Stop the loop when the inp arr is exhausted and the tasks in the heap
        while (i < N || pq.size()) {
            if (pq.empty()) {
                time = max(time, (long)tasks[i][0]);
            }

            // push all the tasks in the arr whose enqueueTime <= currTime into the heap
            while (i < N && time >= tasks[i][0]) {
                pq.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }

            auto [pro, idx] = pq.top();
            pq.pop();

            // handle the task and increase the curr time by the processing time
            time += pro;
            res.push_back(idx);
        }
        return res;
    }
};
