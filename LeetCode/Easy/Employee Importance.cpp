#include <bits/stdc++.h>
using namespace std;

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// TC: O(1), SC: O(N)

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto x : employees) mp[x->id] = x;

        int sum = 0;
        queue<Employee*> Q;
        Q.push(mp[id]);
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            for (int x : p->subordinates) {
                Q.push(mp[x]);
            }
            sum += p->importance;
        }
        return sum;
    }
};