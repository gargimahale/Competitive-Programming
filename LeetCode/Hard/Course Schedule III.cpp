#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if (courses.size() == 0) return 0;
        sort(begin(courses), end(courses), [&](auto a, auto b) {
            return a[1] < b[1];
        });

        priority_queue<int> heap;
        int now = 0;

        for (int i = 0; i < courses.size(); ++i) {
            heap.push(courses[i][0]);
            now += courses[i][0];
            
            if (now > courses[i][1]) {
                now -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};